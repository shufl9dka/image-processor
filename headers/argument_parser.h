#ifndef IMAGEPROCESSOR_ARGUMENT_PARSER_H
#define IMAGEPROCESSOR_ARGUMENT_PARSER_H


#include <utility>
#include <variant>
#include <vector>
#include <string>


namespace ArgumentParser {
    using ParameterType = std::variant<int32_t, double>;

    struct Arguments {
        struct FilterParameters {
            std::string filter_name;
            std::vector<ParameterType> parameters;

            FilterParameters(std::string _filter_name, std::vector<ParameterType> _parameters) :
                    filter_name(std::move(_filter_name)), parameters(std::move(_parameters)) {}
        };

        std::string src_path;
        std::string dest_path;
        std::vector<FilterParameters> filer_parameters;
    };

    Arguments ParseArguments(int argc, char *argv[]);
};


#endif //IMAGEPROCESSOR_ARGUMENT_PARSER_H
