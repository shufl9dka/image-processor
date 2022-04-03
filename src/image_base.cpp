#include "../headers/image_base.h"

ImageBase::PixelMap ImageBase::GetPixelMap() const {
    return pixel_map;
}

void ImageBase::SetPixelMap(const ImageBase::PixelMap& new_pixel_map) {
    pixel_map = new_pixel_map;
}
