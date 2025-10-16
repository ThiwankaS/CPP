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
bool PmergeMe::isSortted(const T& data) {
    for(auto it = data.begin() + 1; it < data.end();it++) {
        if(*it < *(it - 1)){
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

template <typename T>
T next(T it, int steps) {
    std::advance(it, steps);
    return (it);
}

template <typename T>
void PmergeMe::swap_pair(T it, int steps) {
    T start = next(it, -steps + 1);
    T end = next(it, steps);
    while(start != end) {
        std::iter_swap(start, next(start, steps));
        start++;
    }
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
    bool is_odd = no_of_paris % 2 == 1 ? true : false;

    // an iterator to pointing the first element of the container
    Iterator start = container.begin();
    // an iterator to pointing the last comparable element of the container
    Iterator end = next(start, span);

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
        << " level : " << level
        << " no of pairs :" << no_of_paris
        << " is odd : " << is_odd << "\n";

    std::vector<int>Main;
    std::vector<int>Pend;

    Main.insert(Main.end(), start, std::next(start, (level * 2)));

    for(Iterator it = (start + (level * 2)); it != end; it += (level * 2)) {
        Pend.insert(Pend.end(), it, std::next(it, level));
        Main.insert(Main.end(), std::next(it, level), std::next(it, (level * 2)));
    }

    print("Container : ", container);
    print("Main : ", Main);
    print("Pend : ", Pend);
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
