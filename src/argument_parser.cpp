#include "../headers/exceptions.h"
#include "../headers/argument_parser.h"

ArgumentParser::Arguments ArgumentParser::ParseArguments(int argc, char* argv[]) {
    ArgumentParser::Arguments result;
    result.src_path = argv[1];
    result.dest_path = argv[2];

    for (size_t i = 3; i < argc; ++i) {
        if (argv[i][0] == '-') {
            result.filer_parameters.emplace_back(std::string(argv[i]).substr(1),
                                                 std::vector<ArgumentParser::ParameterType>());
        } else {
            if (result.filer_parameters.empty()) {
                throw IncorrectArgumentsError();
            }
            if (std::string(argv[i]).find('.') != std::string::npos) {
                result.filer_parameters.back().parameters.emplace_back(std::stod(argv[i]));
            } else {
                result.filer_parameters.back().parameters.emplace_back(std::stoi(argv[i]));
            }
        }
    }
    return result;
}
