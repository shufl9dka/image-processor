#ifndef IMAGEPROCESSOR_MEDIAN_BLUR_H
#define IMAGEPROCESSOR_MEDIAN_BLUR_H

#include "../../headers/filters/base_filters.h"

class MedianBlurFilter : public BaseFilter {
public:
    void ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const override;
};

#endif //IMAGEPROCESSOR_MEDIAN_BLUR_H
