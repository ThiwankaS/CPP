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
bool PmergeMe::compare(T l_value,T r_value) {
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

    typedef typename T::iterator Iterator;

    size_t size = container.size();
    int no_of_paris = size / level;
    if(no_of_paris < 2) {
        return ;
    }

    size_t comparable = no_of_paris / 2;
    size_t span = comparable * 2 * level;
    //bool is_odd = no_of_paris % 2 == 1;
    Iterator start = container.begin();
    Iterator end = std::next(start, span);

    std::vector<int> main_chain;
    std::vector<int> pend_chain;
    std::vector<int> sorted;
    std::vector<int> stragler;

    main_chain.reserve(size / 2);
    main_chain.reserve((size + 1) / 2);
    sorted.reserve(size);
    stragler.reserve(size - span);

    for(Iterator it = start; it != end; std::advance(it, (2 * level))) {
        Iterator a0,b0,a1,b1, tailA, tailB;

        a0 = it; a1 = std::next(a0, level); tailA = std::prev(a1);
        b0 = a1; b1 = std::next(b0, level); tailB = std::prev(b1);

        if(compare(tailB, tailA)) {
            std::swap_ranges(a0, a1, b0);
        }
    }

    for(Iterator it = start; it != end; std::advance(it, (2 * level))) {
        Iterator a0,b0,a1,b1;
        a0 = it; a1 = std::next(a0, level);
        b0 = a1; b1 = std::next(b0, level);
        pend_chain.insert(pend_chain.end(), a0, a1);
        main_chain.insert(main_chain.end(), b0, b1);
    }

    if(no_of_paris - (comparable * 2) == 1) {
        pend_chain.insert(pend_chain.end(), end, std::next(end, level));
        stragler.insert(stragler.end(), std::next(end, level), container.end());
    }else {
        stragler.insert(stragler.end(), end, container.end());
    }
    //std::vector<int>jacob = {1,3,5,11,23,45};
    main_chain.insert(main_chain.begin(), pend_chain.begin(), std::next(pend_chain.begin(), level));

    print("container : ", container);
    std::cout << "level : " << level << "\n";
    print("main : ", main_chain);
    print("pend : ", pend_chain);
    print("straggler : ", stragler);

    std::vector<Iterator>pend_ptrs;
    std::vector<Iterator>main_ptrs;
    for(Iterator it = std::next(pend_chain.begin(), level); it != pend_chain.end();std::advance(it, level)) {
        Iterator b1 = std::next(it, level);
        Iterator tailB = std::prev(b1);
        pend_ptrs.push_back(tailB);
    }

    for(auto key = pend_ptrs.begin(); key != pend_ptrs.end();key++) {
        main_ptrs.clear();
        for(Iterator it = main_chain.begin(); it != main_chain.end();std::advance(it, level)) {
            Iterator a1 = std::next(it, level);
            Iterator tailA = std::prev(a1);
            main_ptrs.push_back(tailA);
        }
        auto insert = std::upper_bound(
            main_ptrs.begin(),
            main_ptrs.end(),
            *key,
            [](Iterator a, Iterator b) {
                return ( *a < *b);
            }
        );
        main_chain.insert(std::next(insert, -level), std::next(*key, -level), *key);
    }
    std::cout << "main ptrs : <";
    for(auto it = main_ptrs.begin(); it != main_ptrs.end();it++){
        std::cout << **it <<",";
    }
    std::cout << ">\n";
        std::cout << "pend ptrs : <";
    for(auto it = pend_ptrs.begin(); it != pend_ptrs.end();it++){
        std::cout << **it <<",";
    }
    std::cout << ">\n";
    merge_insertion_sort(container, level * 2);
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
