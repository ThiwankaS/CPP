#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

/*
    base example
    11 2 17 0 16 8 15 6 10 3 7 1 18 9 19 14 12 5 20 4 13
    11 2 6 17 16 8 6 15 10 3 7 1 18 19 9 14 12 5 20 4 13
    ./PmergeMe `shuf -i 1-100000 -n 21 | tr "\n" " "`
*/

int main (int argc, char *argv[]) {

    PmergeMe pm;
    std::vector<int> input;
    int value;

    if(argc > 1) {

        if(argc > 10001) {
            std::cerr << "Too many numbers !\n";
            return (EXIT_FAILURE);
        }

        try {

            for(int i = 1; i < argc;i++) {
                if(PmergeMe::isValid(argv[i])){
                    value = PmergeMe::toInt(argv[i]);
                    input.push_back(value);
                }
            }

            PmergeMe::performance_benchmark(input);

        } catch (const std::exception& e) {
            std::cerr << e.what() << "\n";
        }
    } else {
        std::cerr << "Invalid program launch !\n";
        std::cerr << "use format \n\t ./PmergeMe [arg1 arg2 arg3 ..... argn]\n";
    };
    return (EXIT_SUCCESS);
}
