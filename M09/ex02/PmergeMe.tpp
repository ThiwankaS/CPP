#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::print(const std::string& msg, Container data){
    std::cout << msg;
    for(auto it = data.begin(); it != data.end(); std::advance(it, 1)){
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

template <typename Container, typename Iterator>
std::unordered_map<int, Iterator> PmergeMe::updateIndexes(Container& data) {
    std::unordered_map<int, Iterator> indexes;
    for(auto it = data.begin(); it != data.end(); std::advance(it, 1)) {
        auto found = indexes.find(*it);
        if(found == indexes.end()) {
            indexes[*it] = it;
        }
    }
    return (indexes);
}

template <typename Container>
bool PmergeMe::is_sorted(Container& data) {
    size_t size = data.size();
    if(size <= 1) {
        return (true);
    }
    for(size_t i = 1; i < size; i++) {
        if(data[i] < data[i - 1]) {
            return (false);
        }
    }
    return (true);
}

template <typename Time>
void PmergeMe::performance_report(const std::string& type, Time& duration, bool status, size_t size, int comparissons) {
    std::string msg;

    status ? msg = " Success! " : msg = " Failed! ";

    std::cout << " Performance analysis [ "
            << HIGLIGHT_START
            << type
            << HIGLIGHT_END
            << " ] : \n";

    std::cout << std::setw(50)
            << " No of elements : "
            << size
            << "\n";

    std::cout << std::setw(50)
            << " Time spent : "
            << std::setprecision(8)
            << HIGLIGHT_START
            << duration.count()
            << " µs "
            << HIGLIGHT_END
            << "\n";

    std::cout << std::setw(50)
            << " No of comparissons : "
            << comparissons
            << "\n";

    std::cout << std::setw(50)
            << " Sorting process status : "
            << HIGLIGHT_START
            << msg
            << HIGLIGHT_END
            << "\n";
}
