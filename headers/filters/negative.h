#ifndef IMAGEPROCESSOR_NEGATIVE_H
#define IMAGEPROCESSOR_NEGATIVE_H

#include "../../headers/filters/base_filters.h"

class NegativeFilter : public BaseFilter {
public:
    void ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const override;
};

#endif //IMAGEPROCESSOR_NEGATIVE_H
