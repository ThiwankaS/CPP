#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <algorithm>
#include <limits>

#define FORMAT "^\\+?([0-9]\\d*)$"

#include "CustomeException.hpp"

class PmergeMe {
    private:
        static const std::regex Number_FMT;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other) = delete;
        PmergeMe& operator=(const PmergeMe& other) = delete;
        ~PmergeMe();

        struct InvalidArguments : public CustomeException {
            InvalidArguments(const std::string& str):
                CustomeException(str){}
        };

        static void sort_vector(void);
        static bool isValid(std::string str);
        static int toInt(const char* arg);

        template <typename Container>
        static void print(const std::string& msg, Container data);
};

#include "PmergeMe.tpp"
