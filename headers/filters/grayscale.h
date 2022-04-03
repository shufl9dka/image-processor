#ifndef IMAGEPROCESSOR_GRAYSCALE_H
#define IMAGEPROCESSOR_GRAYSCALE_H

#include "../../headers/filters/base_filters.h"

class GrayscaleFilter : public BaseFilter {
public:
    void ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const override;

    [[nodiscard]] static ImageBMP::PixelMap GrayscaleTransform(const ImageBMP::PixelMap& input_map);
};

#endif //IMAGEPROCESSOR_GRAYSCALE_H
