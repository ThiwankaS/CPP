#include "PmergeMe.hpp"

const std::regex PmergeMe::Number_FMT(FORMAT);

int PmergeMe::comparissons = 0;
int PmergeMe::sorting = 0;
int PmergeMe::initial = 0;
int PmergeMe::insertion = 0;

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort_vector(void) {
    std::cout << " I am sorter \n";
}

bool PmergeMe::isValid(std::string str){
    if (!std::regex_match(str, Number_FMT)) {
        throw InvalidArguments("Only positve integers allowed !");
    }
    return (true);
}

int PmergeMe::toInt(const char* arg) {
    long int value;

    try {
            value = std::stol(arg);
            if(value > std::numeric_limits<int>::max()) {
                throw InvalidArguments("Contains number exceeding MAX_INT !");
            }
            return (value);
    } catch (const std::out_of_range& e) {
        throw InvalidArguments("Contains number exceeding MAX_INT !");
    } catch (const std::invalid_argument& e) {
        throw InvalidArguments("Contains non numerical arguments !");
    }
}

bool PmergeMe::compare(int a, int b) {
    PmergeMe::comparissons++;
    PmergeMe::sorting++;
    return (a > b);
}

size_t PmergeMe::jacob_number(ssize_t index) {

    if(index <= 0) {
        return (0);
    }

    long double t1 = std::pow(2.0L,(long double)index);
    long double t2 = std::pow(-1.0L,(long double)index);
    long double result = std::round((t1 - t2) / 3.0L);
    return ((size_t)result);
}

void PmergeMe::sort_vector(std::vector<int>& data, size_t level) {

    typedef std::vector<int>::iterator Iterator;
    typedef std::unordered_map<int, Iterator> Index;
    typedef std::pair<Iterator, int>Element;

    std::vector<Element>Pend_chain;
    Index indexes;
    std::vector<int>Main_chain;

    size_t size = data.size();
    size_t pair_size = level * 2;
    size_t no_of_pairs = size / pair_size;
    size_t span = no_of_pairs * pair_size;

    if(pair_size > size) {
        return;
    }

    Iterator it = data.begin();
    Iterator last = std::next(it, span);
    //Iterator end = data.end();
    Iterator a0,a1,tailA,b0,b1,tailB;

    while (it != last) {
        a0 = it; a1 = std::next(a0, level); tailA = std::prev(a1);
        b0 = a1; b1 = std::next(b0, level); tailB = std::prev(b1);
        if(compare(*tailA, *tailB)) {
            std::rotate(b0, a0, a1);
        }
        it = std::next(it, 2 * level);   
    }

    PmergeMe::print("data   : ", data);
    PmergeMe::sort_vector(data, (level * 2));
}
