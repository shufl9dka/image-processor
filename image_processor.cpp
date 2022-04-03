#include <string>
#include <iostream>
#include "headers/argument_parser.h"
#include "headers/image_bmp.h"
#include "headers/controller.h"


void PrintHelp() {
    std::cout << "Usage: image_processor {src} {dst} [-{filter-1} [param1] [param2] ...]"
              << " [-{filter-2} [param1] [param2] ...]"
              << std::endl << std::endl;

    std::cout << "List of available filters:" << std::endl;
    std::cout << "-crop [int:width] [int:height]" << std::endl;
    std::cout << "-gs" << std::endl;
    std::cout << "-sharp" << std::endl;
    std::cout << "-edge [float:threshold]" << std::endl;
    std::cout << "-blur [float:sigma]" << std::endl;
    std::cout << "-median [int:size]" << std::endl;
}


int main(int argc, char *argv[]) {
    if (argc <= 1 || std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        PrintHelp();
        return 0;
    }

    ArgumentParser::Arguments arguments = ArgumentParser::ParseArguments(argc, argv);
    ImageBMP img(arguments.src_path);
    Controller::RunPipeline(img, arguments.filer_parameters);
    img.Save(arguments.dest_path);

    return 0;
}
