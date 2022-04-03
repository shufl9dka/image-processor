#ifndef IMAGEPROCESSOR_CONTROLLER_H
#define IMAGEPROCESSOR_CONTROLLER_H

#include <string>
#include <unordered_map>
#include "argument_parser.h"
#include "image_bmp.h"

#include "filters/base_filters.h"

namespace Controller {
    std::unordered_map<std::string, BaseFilter*> GetFilterMap();

    void RunPipeline(ImageBMP& img, const std::vector<ArgumentParser::Arguments::FilterParameters>& filter_parameters);
}

#endif //IMAGEPROCESSOR_CONTROLLER_H
