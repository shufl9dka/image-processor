#include <cmath>
#include "../../headers/filters/grayscale.h"

const uint8_t MAX_PIXEL_VALUE = 255;

ImageBMP::PixelMap GrayscaleFilter::GrayscaleTransform(const ImageBMP::PixelMap& input_map) {
    const double RED_WEIGHT = 0.299;
    const double GREEN_WEIGHT = 0.587;
    const double BLUE_WEIGHT = 0.114;

    ImageBMP::PixelMap result_map = input_map;
    for (auto& row : result_map) {
        for (auto& pixel : row) {
            double brightness = pixel.red / (double) MAX_PIXEL_VALUE * RED_WEIGHT +
                                pixel.green / (double) MAX_PIXEL_VALUE * GREEN_WEIGHT +
                                pixel.green / (double) MAX_PIXEL_VALUE * BLUE_WEIGHT;
            pixel.red = pixel.green = pixel.blue = static_cast<uint8_t>(
                    std::round(std::max(std::min(brightness, 1.0), 0.0) * MAX_PIXEL_VALUE)
            );
        }
    }
    return result_map;
}


void GrayscaleFilter::ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const {
    auto pixel_map = GrayscaleTransform(img.GetPixelMap());
    img.SetPixelMap(pixel_map);
}
