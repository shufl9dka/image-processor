#include "../../headers/exceptions.h"
#include "../../headers/filters/crop.h"

void CropFilter::ApplyFilter(ImageBMP &img, const std::vector<ArgumentParser::ParameterType>& parameters) const {
    int32_t width;
    int32_t height;
    try {
        width = std::get<int32_t>(parameters[0]);
        height = std::get<int32_t>(parameters[1]);
    } catch (std::exception &e) {
        throw IncorrectArgumentsError();
    }

    ImageBMP::PixelMap pixel_map = img.GetPixelMap();
    pixel_map.resize(width);
    for (size_t i = 0; i < height; ++i) {
        pixel_map[i].resize(width);
    }

    img.SetPixelMap(pixel_map);
}
