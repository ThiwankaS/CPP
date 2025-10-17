#include "PmergeMe.hpp"

int PmergeMe::number_of_comparissons = 0;

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other){
    (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if(this != &other){
        (void)other;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

template <typename T>
bool PmergeMe::isSorted(const T& data) {
    if (data.size() < 2) {
        return (true);
    }
    for(auto it = std::next(data.begin()); it < data.end();it++) {
        if(*it < *(std::prev(it))){
            return (false);
        }
    }
    return (true);
}

template <typename T>
bool PmergeMe::compare(T l_value, T r_value) {
    PmergeMe::number_of_comparissons++;
    return (*l_value < *r_value);
}

/**
 * this function will return the correspoding Jacobsthal number
 * at nth index, starting from 0th index
*/
long int PmergeMe::jacobsthal_number(long int n) {
    return (round(
        (pow(2, n) - pow(-1, n)) / 3
    ));
}

template <typename T>
void PmergeMe::merge_insertion_sort(T& container, int level) {
    // declaring an iterator type of container
    typedef typename T::iterator Iterator;

    // calculate the no of pairs can be form
    int no_of_paris = container.size() / level;
    // if no of pairs less than 2 there is nothing to compare
    if(no_of_paris < 2) {
        return ;
    }

    size_t comparable = no_of_paris / 2;
    size_t span = comparable * 2 * level;

    // if there are odd no of pairs then is_odd will be true
    bool is_odd = no_of_paris % 2 == 1;

    // an iterator to pointing the first element of the container
    Iterator start = container.begin();
    // an iterator to pointing the last comparable element of the container
    Iterator end = std::next(start, span);

    // comparing pairs and swap if current_pair < previous_pair
    for(Iterator it = start; it != end; std::advance(it, (2 * level))) {
        Iterator a0,b0,a1,b1, tailA, tailB;

        a0 = it; a1 = std::next(a0, level); tailA = std::prev(a1);
        b0 = a1; b1 = std::next(b0, level); tailB = std::prev(b1);

        if(compare(tailB, tailA)) {
            std::swap_ranges(a0, a1, b0);
        }
    }

    // recursion call to self-fuction
    merge_insertion_sort(container, level * 2);

    std::cout
        << " size : " << container.size()
        << " level : " << level
        << " no of pairs :" << no_of_paris
        << " comparable : " << comparable
        << " is odd : " << is_odd << "\n";

    // two vectors of iterators to store pointers to value
    std::vector<Iterator> Main_ptrs;
    std::vector<Iterator> Pend_ptrs;

    for(Iterator it = start; it != end; std::advance(it, (2 * level))) {
        Main_ptrs.push_back(std::next(it, level));
        Pend_ptrs.push_back(it);
    }

    if(no_of_paris - (comparable * 2) == 1) {
        Pend_ptrs.push_back(end);
    }

    int pend_count = Pend_ptrs.size();
    int jacob_index = 2;
    int previous_jacob_number = 1;
    int current_jacob_number = jacobsthal_number(jacob_index);

    while(pend_count > 0) {
        int start_k = previous_jacob_number + 1;
        int end_k = std::min(no_of_paris, current_jacob_number);
        for(int k = end_k; k >= start_k;k--){
            std::cout << "k value : " << k << "\n";
        }
        previous_jacob_number = current_jacob_number;
        jacob_index++;
        current_jacob_number = jacobsthal_number(jacob_index);
        pend_count--;
    }
}

void PmergeMe::sort_vec(std::vector<int>& vec) {
    merge_insertion_sort<std::vector<int> >(vec, 1);
}

template <typename T>
void PmergeMe::print(std::string str,T& nums) {
    std::cout << str << "("
         << nums.size()
         << ") <";
    for(auto it = nums.begin(); it < nums.end();it++) {
        std::cout << *it << ",";
    }
    std::cout << "> \n";
}
