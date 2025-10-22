#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <algorithm>
#include <limits>
#include <iterator>
#include <cmath>
#include <vector>
#include <unordered_map>

#define FORMAT "^\\+?([0-9]\\d*)$"

#include "CustomeException.hpp"

class PmergeMe {
    private:
        static const std::regex Number_FMT;
    public:
        static int comparissons;
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
        static void sort_vector(std::vector<int>& data);
        static bool compare(int a, int b);
        static size_t jacob_number(ssize_t index);


        template <typename Container>
        static void print(const std::string& msg, Container data);

        template <typename Iterator>
        static std::unordered_map<int, Iterator> updateIndexes(std::vector<int>& data);
};

#include "PmergeMe.tpp"
