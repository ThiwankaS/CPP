#pragma once

#include <iostream>
#include <string>
#include <iterator>

#include "CustomeException.hpp"

class PmergeMe {

    private:
        static int number_of_comparissons;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        struct InvalidInput : public CustomeException {
            InvalidInput(const std::string& str):
                CustomeException(str){}
        };

        template <typename T>
        bool isSortted(const T& data);

        template <typename T>
        bool compare(T r_value, T l_value);

        template <typename T>
        void swap_pair(T it, int level);

        template <typename T>
        void merge_insertion_sort(T& container, int level);
};

#include "PmergeMe.tpp"
