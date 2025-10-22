#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::print(const std::string& msg, Container data){
    std::cout << msg;
    for(auto it = data.begin(); it != data.end(); std::advance(it, 1)){
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

template <typename Iterator>
std::unordered_map<int, Iterator> PmergeMe::updateIndexes(std::vector<int>& data) {
    std::unordered_map<int, Iterator> indexes;
    for(auto it = data.begin(); it != data.end(); it++) {
        auto found = indexes.find(*it);
        if(found == indexes.end() || it < found->second) {
            indexes[*it] = it;
        }
    }
    indexes[-1] = data.end();
    return (indexes);
}
