#include <algorithm>
#include "../../headers/exceptions.h"
#include "../../headers/filters/median_blur.h"

ImageBMP::Color MedianColor(const std::vector<ImageBMP::Color>& color_list) {
    std::vector<uint8_t> red_brightness_list(color_list.size());
    std::vector<uint8_t> green_brightness_list(color_list.size());
    std::vector<uint8_t> blue_brightness_list(color_list.size());
    for (size_t i = 0; i < color_list.size(); ++i) {
        red_brightness_list[i] = color_list[i].red;
        green_brightness_list[i] = color_list[i].green;
        blue_brightness_list[i] = color_list[i].blue;
    }
    std::sort(red_brightness_list.begin(), red_brightness_list.end());
    std::sort(green_brightness_list.begin(), green_brightness_list.end());
    std::sort(blue_brightness_list.begin(), blue_brightness_list.end());
    size_t middle = color_list.size() / 2;
    return {red_brightness_list[middle], green_brightness_list[middle], blue_brightness_list[middle]};
}

void MedianBlurFilter::ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const {
    int32_t window_size;
    try {
        window_size = std::get<int32_t>(parameters[0]);
        if (window_size < 1) {
            throw IncorrectArgumentsError();
        }
    } catch (std::exception& e) {
        throw IncorrectArgumentsError();
    }

    ImageBMP::PixelMap input_map = img.GetPixelMap();
    size_t new_width = input_map.back().size() + 1 - window_size;
    size_t new_height = input_map.size() + 1 - window_size;

    ImageBMP::PixelMap result_map(new_height, std::vector<ImageBMP::Color>(new_width));
    for (size_t i = 0; i < new_height; ++i) {
        for (size_t j = 0; j < new_width; ++j) {
            std::vector<ImageBMP::Color> color_list;
            for (size_t window_i = 0; window_i < window_size; ++window_i) {
                for (size_t window_j = 0; window_j < window_size; ++window_j) {
                    color_list.emplace_back(input_map[i + window_i][j + window_j]);
                }
            }
            result_map[i][j] = MedianColor(color_list);
        }
    }
    img.SetPixelMap(result_map);
}
