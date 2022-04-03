#include <cmath>
#include "../../headers/exceptions.h"
#include "../../headers/filters/gaussian_blur.h"

inline double G(double sigma, int32_t x) {
    return exp(-(x * x) / (2 * sigma * sigma)) / sqrt(2 * M_PI * sigma * sigma);
}

std::vector<double> GenerateGaussianMatrixLine(double sigma) {
    size_t size = std::ceil(6 * sigma);
    if (size % 2 == 0) {
        ++size;
    }
    std::vector<double> result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = G(sigma, static_cast<int32_t>(i) - static_cast<int32_t>(size / 2));
    }
    return result;
}

void GaussianBlurFilter::ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const {
    double sigma;
    try {
        sigma = std::get<double>(parameters[0]);
    } catch (std::exception& e) {
        throw IncorrectArgumentsError();
    }

    auto gaussian_line = GenerateGaussianMatrixLine(sigma);
    Matrix<double> gaussian_matrix_horizontal = Matrix<double>(1, gaussian_line);
    Matrix<double> gaussian_matrix_vertical = Matrix<double>(gaussian_line.size());
    for (size_t i = 0; i < gaussian_matrix_vertical.size(); ++i) {
        gaussian_matrix_vertical[i].emplace_back(gaussian_line[i]);
    }

    auto pixel_map = img.GetPixelMap();
    pixel_map = ApplyMatrix(pixel_map, gaussian_matrix_horizontal);
    pixel_map = ApplyMatrix(pixel_map, gaussian_matrix_vertical);
    img.SetPixelMap(pixel_map);
}
