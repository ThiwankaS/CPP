#pragma once

#include <iostream>
#include <string>
#include <exception>

class ScalarConverter {
    public:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter& other) = delete;
        ScalarConverter& operator=(const ScalarConverter& other) = delete;
        ~ScalarConverter() = delete;

        static void convert(const std::string& arg);
};
