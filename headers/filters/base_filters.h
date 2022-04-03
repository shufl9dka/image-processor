#ifndef IMAGEPROCESSOR_BASE_FILTERS_H
#define IMAGEPROCESSOR_BASE_FILTERS_H

#include <vector>

#include "../image_bmp.h"
#include "../argument_parser.h"

template<typename T>
using Matrix = std::vector<std::vector<T>>;

class BaseFilter {
public:
    virtual void ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const {}
};


class MatrixBaseFilter : public BaseFilter {
protected:
    [[nodiscard]] ImageBMP::PixelMap ApplyMatrix(const ImageBMP::PixelMap& input_map, const Matrix<double>& matrix) const;
};

#endif //IMAGEPROCESSOR_BASE_FILTERS_H
