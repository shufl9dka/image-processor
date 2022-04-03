cmake_minimum_required(VERSION 3.21)
project(ImageProcessor)

set(CMAKE_CXX_STANDARD 17)

add_executable(ImageProcessor image_processor.cpp src/argument_parser.cpp headers/argument_parser.h headers/image_bmp.h src/image_bmp.cpp headers/filters/base_filters.h headers/controller.h src/controller.cpp src/filters/base_filters.cpp headers/filters/crop.h src/filters/crop.cpp headers/exceptions.h headers/filters/sharpening.h src/filters/sharpening.cpp headers/filters/negative.h src/filters/negative.cpp headers/filters/grayscale.h src/filters/grayscale.cpp headers/filters/edge_detection.h src/filters/edge_detection.cpp headers/filters/gaussian_blur.h src/filters/gaussian_blur.cpp headers/filters/median_blur.h src/filters/median_blur.cpp headers/image_base.h src/image_base.cpp)
