#include "../headers/exceptions.h"
#include "../headers/controller.h"

#include "../headers/filters/crop.h"
#include "../headers/filters/grayscale.h"
#include "../headers/filters/negative.h"
#include "../headers/filters/sharpening.h"
#include "../headers/filters/edge_detection.h"
#include "../headers/filters/gaussian_blur.h"
#include "../headers/filters/median_blur.h"

std::unordered_map<std::string, BaseFilter *> Controller::GetFilterMap() {
    return {{"crop",   new CropFilter()},
            {"gs",     new GrayscaleFilter()},
            {"neg",    new NegativeFilter()},
            {"sharp",  new SharpeningFilter()},
            {"edge",   new EdgeDetectionFilter()},
            {"blur",   new GaussianBlurFilter()},
            {"median", new MedianBlurFilter()}};
}

void Controller::RunPipeline(ImageBMP& img, const std::vector<ArgumentParser::Arguments::FilterParameters>& filters) {
    auto filter_map = GetFilterMap();
    for (const auto& filter : filters) {
        if (filter_map.count(filter.filter_name) == 0) {
            throw IncorrectArgumentsError();
        }
        filter_map[filter.filter_name]->ApplyFilter(img, filter.parameters);
    }
}
