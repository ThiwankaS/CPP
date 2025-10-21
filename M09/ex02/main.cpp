#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

/*
    base example
    11 2 17 0 16 8 15 6 10 3 7 1 18 9 19 14 12 5 20 4 13
*/

int main (int argc, char *argv[]) {
    PmergeMe pm;
    std::vector<int> data;
    int value;

    if(argc > 2) {
        try {
            for(int i = 1; i < argc;i++) {
                if(PmergeMe::isValid(argv[i])){
                    value = PmergeMe::toInt(argv[i]);
                    data.push_back(value);
                }
            }
            PmergeMe::print("Before : ", data);
        } catch (const std::exception& e) {
            std::cerr << e.what() << "\n";
        }
    } else {
        std::cerr << "Invalid program launch !\n";
        std::cerr << "use format \n\t ./PmergeMe [arg1 arg2 arg3 ..... argn]\n";
    };
    return (EXIT_SUCCESS);
}
