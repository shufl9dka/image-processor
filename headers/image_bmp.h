#ifndef IMAGEPROCESSOR_IMAGE_BMP_H
#define IMAGEPROCESSOR_IMAGE_BMP_H

#include <cstdint>
#include <string>
#include <vector>

#pragma pack(push, 1)

class ImageBMP {
public:
    struct BitMapFileHeader {
        uint16_t type;
        uint32_t size;
        uint16_t reserved_1;
        uint16_t reserved_2;
        uint32_t offset_bytes;
    };

    struct BitMapInfoHeader {
        uint32_t size;
        int32_t width;
        int32_t height;
        uint16_t planes;
        uint16_t bit_count;
        uint32_t compression;
        uint32_t size_image;
        int32_t resolution_horizontal;
        int32_t resolution_vertical;
        uint32_t used_colors;
        uint32_t important_colors;
    };

    struct Color {
        uint8_t red;
        uint8_t green;
        uint8_t blue;

        Color(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}
        Color() : red(0), green(0), blue(0) {}
    };

    using PixelMap = std::vector<std::vector<Color>>;

    explicit ImageBMP(const std::string& filename);

    void Save(const std::string& filename);

    [[nodiscard]] std::vector<std::vector<Color>> GetPixelMap() const;

    void SetPixelMap(const PixelMap& new_pixel_map);

private:
    BitMapFileHeader bmp_header{};
    BitMapInfoHeader dib_header{};
    std::vector<std::vector<Color>> pixel_map;
};

#pragma pack(pop)

#endif //IMAGEPROCESSOR_IMAGE_BMP_H
