#include <cmath>
#include "../../headers/filters/base_filters.h"

const uint8_t MAX_PIXEL_VALUE = 255;

ImageBMP::PixelMap MatrixBaseFilter::ApplyMatrix(const ImageBMP::PixelMap& input_map, const Matrix<double>& matrix) const {
    size_t new_map_height = input_map.size() + 1 - matrix.size();
    size_t new_map_width = input_map.back().size() + 1 - matrix.back().size();
    ImageBMP::PixelMap result_map(new_map_height, std::vector<ImageBMP::Color>(new_map_width));

    for (int32_t i = 0; i < new_map_height; ++i) {
        for (int32_t j = 0; j < new_map_width; ++j) {
            double red = 0.0;
            double green = 0.0;
            double blue = 0.0;
            for (int32_t matrix_i = 0; matrix_i < matrix.size(); ++matrix_i) {
                for (int32_t matrix_j = 0; matrix_j < matrix[matrix_i].size(); ++matrix_j) {
                    red += (input_map[i + matrix_i][j + matrix_j].red / (double)MAX_PIXEL_VALUE) * matrix[matrix_i][matrix_j];
                    green += (input_map[i + matrix_i][j + matrix_j].green / (double)MAX_PIXEL_VALUE) * matrix[matrix_i][matrix_j];
                    blue += (input_map[i + matrix_i][j + matrix_j].blue / (double)MAX_PIXEL_VALUE) * matrix[matrix_i][matrix_j];
                }
            }
            result_map[i][j] = ImageBMP::Color(
                    static_cast<uint8_t>(std::round(std::max(std::min(red, 1.0), 0.0) * MAX_PIXEL_VALUE)),
                    static_cast<uint8_t>(std::round(std::max(std::min(green, 1.0), 0.0) * MAX_PIXEL_VALUE)),
                    static_cast<uint8_t>(std::round(std::max(std::min(blue, 1.0), 0.0) * MAX_PIXEL_VALUE))
            );
        }
    }
    return result_map;
}

ImageBMP::PixelMap CropBaseFilter::CropPixelMap(const ImageBMP::PixelMap& input_map, size_t new_width, size_t new_height) const {
    ImageBMP::PixelMap result_map = input_map;
    result_map.resize(new_height);
    for (size_t i = 0; i < new_height; ++i) {
        result_map[i].resize(new_width);
    }
    return result_map;
}

ImageBMP::PixelMap BaseFilter::GrayscaleTransform(const ImageBMP::PixelMap& input_map) const {
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
