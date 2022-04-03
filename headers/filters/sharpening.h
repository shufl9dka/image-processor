#ifndef IMAGEPROCESSOR_SHARPENING_H
#define IMAGEPROCESSOR_SHARPENING_H

#include "../../headers/filters/base_filters.h"

class SharpeningFilter : public MatrixBaseFilter {
public:
    void ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const override;
};

#endif //IMAGEPROCESSOR_SHARPENING_H
