#ifndef IMAGEPROCESSOR_EDGE_DETECTION_H
#define IMAGEPROCESSOR_EDGE_DETECTION_H

#include "../../headers/filters/base_filters.h"

class EdgeDetectionFilter : public MatrixBaseFilter {
public:
    void ApplyFilter(ImageBMP& img, const std::vector<ArgumentParser::ParameterType>& parameters) const override;
};

#endif //IMAGEPROCESSOR_EDGE_DETECTION_H
