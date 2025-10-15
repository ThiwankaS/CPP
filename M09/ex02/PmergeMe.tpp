#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
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
bool PmergeMe::isSortted(const T& data) {
    for(auto it = data.begin() + 1; it < data.end();it++) {
        if(*it < *(it - 1)){
            return (false);
        }
    }
    return (true);
}

template <typename T>
bool PmergeMe::compare(T r_value, T l_value) {
    PmergeMe::number_of_comparissons++;
    return (* l_value < r_value);
}

template <typename T>
T next(T it, int steps) {
    std::advance(it, steps);
    return (it);
}

template <typename T>
void PmergeMe::swap_pair(T it, int level) {
    T start = next(it, -steps + 1);
    T end = next(it, steps);
    while(start != end) {
        std::iter_swap(start, next(start, level));
        start++;
    }
}

template <typename T>
void PmergeMe::merge_insertion_sort(T& container, int level) {
    typedef typename T::iterator Iterrator;

    // calculate the no of pairs can be form
    int no_of_paris = container.size() / level;
    // if no of pairs less than 2 there is nothing to compare
    if(no_of_paris < 2) {
        return ;
    }

    // if there are odd no of pairs then is_odd will be true
    bool is_odd = no_of_paris % 2 == 1 ? true : false;

    // 
    Iterrator start = container.begin();
    Iterrator last = next(start, container.size());
    Iterrator end = next(last, -(is_odd * level));

    int jump = 2 * level;
}
