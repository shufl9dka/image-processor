#include "../../headers/filters/grayscale.h"

void GrayscaleFilter::ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const {
    auto pixel_map = GrayscaleTransform(img.GetPixelMap());
    img.SetPixelMap(pixel_map);
}
