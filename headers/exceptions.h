#ifndef IMAGEPROCESSOR_EXCEPTIONS_H
#define IMAGEPROCESSOR_EXCEPTIONS_H

#include <exception>

struct IncorrectArgumentsError : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Incorrect argument usage. Run the program with --help argument to get reference.";
    }
};

struct InputReadError : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Unable tp open the input file for reading.";
    }
};

struct InputIsNotBMPError : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "The input file is not BMP image.";
    }
};

struct OutputWriteError : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Unable to open the output file for writing.";
    }
};

#endif //IMAGEPROCESSOR_EXCEPTIONS_H
