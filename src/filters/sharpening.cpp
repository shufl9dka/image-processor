#include "../../headers/filters/sharpening.h"

void SharpeningFilter::ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const {
    const Matrix<double> sharpening_matrix = {{0, -1, 0},
                                              {-1, 5, -1},
                                              {0, -1, 0}};
    auto pixel_map = ApplyMatrix(img.GetPixelMap(), sharpening_matrix);
    img.SetPixelMap(pixel_map);
}
