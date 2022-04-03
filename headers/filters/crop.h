#ifndef IMAGEPROCESSOR_CROP_H
#define IMAGEPROCESSOR_CROP_H

#include "../../headers/filters/base_filters.h"

class CropFilter : public CropBaseFilter {
public:
    void ApplyFilter(ImageBMP &img, const std::vector<ArgumentParser::ParameterType>& parameters) const override;
};

#endif //IMAGEPROCESSOR_CROP_H
