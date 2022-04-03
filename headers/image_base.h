#ifndef IMAGEPROCESSOR_IMAGE_BASE_H
#define IMAGEPROCESSOR_IMAGE_BASE_H

#include <cstdint>
#include <vector>
#include <string>

class ImageBase {
public:
    struct Color {
        uint8_t red;
        uint8_t green;
        uint8_t blue;

        Color(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}
        Color() : red(0), green(0), blue(0) {}
    };

    using PixelMap = std::vector<std::vector<Color>>;

    virtual void Save(const std::string& filename) {};

    [[nodiscard]] std::vector<std::vector<Color>> GetPixelMap() const;

    void SetPixelMap(const PixelMap& new_pixel_map);

protected:
    std::vector<std::vector<Color>> pixel_map;
};

#endif //IMAGEPROCESSOR_IMAGE_BASE_H
