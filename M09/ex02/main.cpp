#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main (int argc, char *argv[]) {

    std::vector<int> data = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13};

    if (argc > 2) {
        (void) argv[1];
        PmergeMe pm;
        pm.print("data", data);
        pm.sort_vec(data);
        pm.print("sorted data : ", data);
        std::cout << "Number of comparissions : "
            << PmergeMe::number_of_comparissons
            << std::endl; 
    }
    return (EXIT_SUCCESS);
}
