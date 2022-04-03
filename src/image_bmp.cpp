#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include "../headers/exceptions.h"
#include "../headers/image_bmp.h"

ImageBMP::ImageBMP(const std::string &filename) {
    std::ifstream in(filename, std::ios_base::in | std::ios_base::binary);
    if (!in.good()) {
        throw InputReadError();
    }

    in.read(reinterpret_cast<char*>(&bmp_header), sizeof(BitMapFileHeader));
    in.read(reinterpret_cast<char*>(&dib_header), sizeof(BitMapInfoHeader));

    if (bmp_header.type != 0x4D42 || dib_header.size != 0x28) {
        throw InputIsNotBMPError();
    }

    uint32_t row_size = dib_header.width * 3;
    uint32_t padding_size = (4 - row_size % 4) % 4;
    char *padding = new char[padding_size];
    char *row_buffer = new char[row_size];

    in.seekg(bmp_header.offset_bytes);
    for (size_t i = 0; i < dib_header.height; ++i) {
        in.read(row_buffer, row_size);
        in.read(padding, padding_size);

        pixel_map.emplace_back(std::vector<Color>(dib_header.width));
        memcpy(reinterpret_cast<char*>(pixel_map.back().data()), row_buffer, row_size);
    }
    std::reverse(pixel_map.begin(), pixel_map.end());

    delete[] padding;
    delete[] row_buffer;
    in.close();
}

void ImageBMP::Save(const std::string& filename) {
    std::ofstream out(filename, std::ios_base::binary);
    if (!out.good()) {
        throw OutputWriteError();
    }

    dib_header.height = static_cast<int32_t>(pixel_map.size());
    if (pixel_map.empty()) {
        dib_header.width = 0;
    } else {
        dib_header.width = static_cast<int32_t>(pixel_map.back().size());
    }
    dib_header.size_image = dib_header.width * dib_header.height * 3;
    bmp_header.size = dib_header.size_image + bmp_header.offset_bytes;

    out.write(reinterpret_cast<const char*>(&bmp_header), sizeof(bmp_header));
    out.write(reinterpret_cast<const char*>(&dib_header), sizeof(dib_header));

    uint32_t row_size = dib_header.width * 3;
    uint32_t padding_size = (4 - row_size % 4) % 4;
    char *padding = new char[padding_size];

    auto pixel_map_rev = pixel_map;
    std::reverse(pixel_map_rev.begin(), pixel_map_rev.end());
    for (size_t i = 0; i < dib_header.height; ++i) {
        out.write(reinterpret_cast<const char*>(pixel_map_rev[i].data()), row_size);
        out.write(padding, padding_size);
    }

    delete[] padding;
    out.close();
}
