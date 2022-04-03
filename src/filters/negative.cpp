#include "../../headers/filters/negative.h"

void NegativeFilter::ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const {
    const uint8_t MAX_PIXEL_VALUE = 255;

    auto pixel_map = img.GetPixelMap();
    for (auto &row : pixel_map) {
        for (auto &pixel : row) {
            pixel.red = MAX_PIXEL_VALUE - pixel.red;
            pixel.green = MAX_PIXEL_VALUE - pixel.green;
            pixel.blue = MAX_PIXEL_VALUE - pixel.blue;
        }
    }
    img.SetPixelMap(pixel_map);
}
