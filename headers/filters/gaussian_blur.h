#ifndef IMAGEPROCESSOR_GAUSSIAN_BLUR_H
#define IMAGEPROCESSOR_GAUSSIAN_BLUR_H

#include "../../headers/filters/base_filters.h"

class GaussianBlurFilter : public MatrixBaseFilter {
public:
    void ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const override;
};

#endif //IMAGEPROCESSOR_GAUSSIAN_BLUR_H
