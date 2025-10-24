#include "PmergeMe.hpp"

const std::regex PmergeMe::Number_FMT(FORMAT);

int PmergeMe::comparissons = 0;
int PmergeMe::sorting = 0;
int PmergeMe::initial = 0;
int PmergeMe::insertion = 0;

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

bool PmergeMe::is_sorted(std::vector<int>& data) {
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

void PmergeMe::ford_jhonson_sort_vec(std::vector<int>& data) {

    typedef std::vector<int>::iterator Iterator;
    typedef std::unordered_map<int, Iterator> Index;
    typedef std::pair<Iterator, int>Element;

    std::vector<Element>Pend_chain;
    Index indexes;
    std::vector<int>Main_chain;

    size_t size = data.size();
    int odd_value = -1;
    bool has_odd = false;

    if(size < 2) {
        return;
    }

    Iterator it = data.begin();
    while(it != data.end()){
        Iterator nxt = std::next(it);
        if(nxt == data.end()) {
            odd_value = *it;
            has_odd = true;
            break;
        }
        if(compare(*it, *nxt)){
            std::iter_swap(it, nxt);
        }
        Main_chain.push_back(*nxt);
        Pend_chain.emplace_back(std::make_pair(it, *nxt));
        it = std::next(nxt);
    }

    PmergeMe::ford_jhonson_sort_vec(Main_chain);

    indexes = PmergeMe::updateIndexes<Iterator>(Main_chain);

    if(Pend_chain.size() >= 1){
        Element element = Pend_chain[0];
        Iterator limit = indexes[element.second];
        int value = *element.first;
        Iterator pos = std::upper_bound(
            Main_chain.begin(),
            limit,
            value,
            [](int a, int b){
                PmergeMe::comparissons++;
                PmergeMe::initial++;
                return (a < b);
            }
        );
        Main_chain.insert(pos, value);
        indexes = PmergeMe::updateIndexes<Iterator>(Main_chain);
    }

    if(Pend_chain.size() >= 2){
        Element element = Pend_chain[1];
        Iterator limit = indexes[element.second];
        int value = *element.first;
        Iterator pos = std::upper_bound(
            Main_chain.begin(),
            limit,
            value,
            [](int a, int b){
                PmergeMe::comparissons++;
                PmergeMe::initial++;
                return (a < b);
            }
        );
        Main_chain.insert(pos, value);
        indexes = PmergeMe::updateIndexes<Iterator>(Main_chain);
    }

    size_t jacob_index = 3;
    size_t previous_jacob_number = 1;
    size_t current_jacob_number;
    while(previous_jacob_number < Pend_chain.size()) {
        current_jacob_number = jacob_number(jacob_index);
        if(current_jacob_number > Pend_chain.size()) {
            current_jacob_number = Pend_chain.size();
        }
        for(size_t k = current_jacob_number; (k > previous_jacob_number && k > 2); k--) {
            Element element = Pend_chain[k - 1];
            Iterator limit = indexes[element.second];
            int value = *element.first;
            Iterator pos = std::upper_bound(
                Main_chain.begin(),
                limit,
                value,
                [](int a, int b) {
                    PmergeMe::comparissons++;
                    PmergeMe::insertion++;
                    return (a < b);
                }
            );
            Main_chain.insert(pos, value);
            indexes = PmergeMe::updateIndexes<Iterator>(Main_chain);
        }
        previous_jacob_number = current_jacob_number;
        jacob_index++;
    }

    if(has_odd) {
        Iterator pos = std::upper_bound(
            Main_chain.begin(),
            Main_chain.end(),
            odd_value,
            [](int a, int b){
                PmergeMe::comparissons++;
                PmergeMe::insertion++;
                return (a < b);
            }
        );
        Main_chain.insert(pos, odd_value);
    }

    data.assign(Main_chain.begin(), Main_chain.end());
}

void PmergeMe::ford_jhonson_sort_deq(std::vector<int>& data) {
    (void) data;
}
