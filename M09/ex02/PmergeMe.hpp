#pragma once

#include <algorithm>
#include <cmath>
#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

#define FORMAT "^\\+?([0-9]\\d*)$"

#define HIGLIGHT_START	"\x1b[1m\x1b[38;2;0;0;0m\x1b[48;2;255;255;170m"
#define HIGLIGHT_END	"\x1b[0m"

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

        static bool isValid(std::string str);
        static int toInt(const char* arg);
        static void ford_jhonson_sort(std::vector<int>& data);
        static void ford_jhonson_sort(std::deque<int>& data);
        static bool compare(int a, int b);
        static size_t jacob_number(ssize_t index);
        static void performance_benchmark(std::vector<int>& input);

        template <typename Container>
        static void print(const std::string& msg, Container data);

        template <typename Container>
        static bool is_sorted(Container& data);

        template <typename Container, typename Iterator>
        static std::unordered_map<int, Iterator> updateIndexes(Container& data);

        template <typename Time>
        static void performance_report(const std::string& type, Time& duration, bool status, size_t size, int comparissons);
};

#include "PmergeMe.tpp"
