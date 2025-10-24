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
    std::vector<int> data;
    std::string status;
    int value;

    if(argc > 1) {
        try {
            for(int i = 1; i < argc;i++) {
                if(PmergeMe::isValid(argv[i])){
                    value = PmergeMe::toInt(argv[i]);
                    data.push_back(value);
                }
            }
            PmergeMe::print("Before : ", data);
            PmergeMe::sort_vector(data);
            PmergeMe::print("After : ", data);
            std::cout << "Comparissons : " << PmergeMe::comparissons << "\n";
            std::cout << "Comparissons (Sorting) : " << PmergeMe::sorting << "\n";
            std::cout << "Comparissons (Intial inserting): " << PmergeMe::initial << "\n";
            std::cout << "Comparissons (Insertion): " << PmergeMe::insertion << "\n";

            PmergeMe::is_sorted(data) ? status = " Success! " : status = " Failed! ";
            std::cout << "Sorting process status : "
                      << HIGLIGHT_START
                      << status
                      << HIGLIGHT_END
                      << "\n";

        } catch (const std::exception& e) {
            std::cerr << e.what() << "\n";
        }
    } else {
        std::cerr << "Invalid program launch !\n";
        std::cerr << "use format \n\t ./PmergeMe [arg1 arg2 arg3 ..... argn]\n";
    };
    return (EXIT_SUCCESS);
}
