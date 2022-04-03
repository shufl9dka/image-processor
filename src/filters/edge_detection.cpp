#include "../../headers/exceptions.h"
#include "../../headers/filters/grayscale.h"
#include "../../headers/filters/edge_detection.h"

const uint8_t MAX_PIXEL_VALUE = 255;

void EdgeDetectionFilter::ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const {
    double threshold;
    try {
        threshold = std::get<double>(parameters[0]);
    } catch (std::exception &e) {
        throw IncorrectArgumentsError();
    }

    auto pixel_map = GrayscaleFilter::GrayscaleTransform(img.GetPixelMap());
    const Matrix<double> edging_matrix = {{0, -1, 0},
                                          {-1, 4, -1},
                                          {0, -1, 0}};
    pixel_map = ApplyMatrix(pixel_map, edging_matrix);

    for (auto &row : pixel_map) {
        for (auto &pixel : row) {
            pixel.red = pixel.green = pixel.blue = pixel.red / (double) MAX_PIXEL_VALUE > threshold ? MAX_PIXEL_VALUE : 0;
        }
    }

    img.SetPixelMap(pixel_map);
}
