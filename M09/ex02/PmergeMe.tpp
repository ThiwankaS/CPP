#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::print(const std::string& msg, Container data){
    std::cout << msg;
    for(auto it = data.begin(); it != data.end(); std::advance(it, 1)){
        std::cout << *it << " ";
    }
    std::cout << "\n";
}
