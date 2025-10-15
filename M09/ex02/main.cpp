#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main (int argc, char *argv[]) {

    std::vector<int> data = {1,2,3,4,5};

    if (argc > 2) {
        PmergeMe pm;
        int i = 1;
        while(i < argc) {
            std::cout << "arg : " << argv[i] << "\n";
            i++;
        }
        if(pm.isSortted(data)) {
            std::cout << "data is sorted !\n";
        } else {
            std::cout << "data is not sorted !\n";
        }
    } else {
        throw PmergeMe::InvalidInput("WTF!");
    }
    return (EXIT_SUCCESS);
}
