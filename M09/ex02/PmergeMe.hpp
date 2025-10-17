#pragma once

#include <iostream>
#include <string>
#include <iterator>
#include <cmath>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include <memory>

#include "CustomeException.hpp"

class PmergeMe {

    private:


    public:
        static int number_of_comparissons;
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        struct InvalidInput : public CustomeException {
            InvalidInput(const std::string& str):
                CustomeException(str){}
        };

        long int jacobsthal_number(long int n);

        void sort_vec(std::vector<int>& vec);

        template <typename T>
        bool isSorted(const T& data);

        template <typename T>
        bool compare(T l_value, T r_value);

        template <typename T>
        void merge_insertion_sort(T& container, int level);

        template <typename T>
        void print(std::string str, T& nums);
};

#include "PmergeMe.tpp"
