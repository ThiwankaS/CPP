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
bool PmergeMe::compare(const T& l_value,const T& r_value) {
    PmergeMe::number_of_comparissons++;
    return (l_value < r_value);
}

size_t PmergeMe::jacobsthal_number(size_t n) {
    return (round(
        (pow(2, n) - pow(-1, n)) / 3
    ));
}

template <typename T>
void PmergeMe::merge_insertion_sort(T& container) {

    static int swapping = 0;
    static int inserton = 0;

    typedef typename T::iterator Iterator;

    size_t size = container.size();

    std::vector<int>main_chain;
    std::vector<int>pend_chain;

    main_chain.reserve(size / 2);
    pend_chain.reserve((size + 1) / 2);

    if(size < 2) {
        return;
    }

    Iterator it = container.begin();
    while(it != container.end()) {
        Iterator first = it++;
        if(it == container.end()) {
            pend_chain.push_back(*first);
            break;
        }
        Iterator second = it++;
        swapping++;
        if(!this->compare(*first, *second)) {
            std::iter_swap(first, second);
        }
        pend_chain.push_back(*first);
        main_chain.push_back(*second);
    }

    this->merge_insertion_sort(main_chain);

    std::vector<int>sorted(main_chain.begin(), main_chain.end());
    if(!pend_chain.empty()) {
        int value = pend_chain[0];
        std::vector<int>::iterator place = std::lower_bound(
            sorted.begin(),
            sorted.end(),
            value,
            [&](const int& lhs, const int& rhs){
                inserton++;
                return this->compare(lhs, rhs);
            }
        );
        sorted.insert(place, value);
    }

    size_t pend_size = pend_chain.size();
    if(pend_size > 1) {
        size_t previous_jacob_number = 1;
        size_t jacob_index = 2;
        while(previous_jacob_number < pend_size) {
            size_t current_jacob_number = jacobsthal_number(jacob_index);
            if(current_jacob_number <= previous_jacob_number ) {
                jacob_index++;
                continue;
            }
            if(current_jacob_number > pend_size) {
                current_jacob_number = pend_size;
            }
            for(size_t i = current_jacob_number; i > previous_jacob_number; i--) {
                int value = pend_chain[i - 1];
                std::vector<int>::iterator insert_position = std::upper_bound(
                    sorted.begin(),
                    sorted.end(),
                    value,
                    [&](const int& lhs, const int& rhs) {
                        inserton++;
                        return this->compare(lhs, rhs);
                    }
                );
                sorted.insert(insert_position, value);
            }
            previous_jacob_number = current_jacob_number;
            jacob_index++;
        }
    }
    container.assign(sorted.begin(), sorted.end());
    std::cout << "swapping comparissons : " << swapping << "\n";
    std::cout << "insertion comparissons : " << inserton << "\n";
}

void PmergeMe::sort_vec(std::vector<int>& vec) {
    merge_insertion_sort<std::vector<int> >(vec);
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
