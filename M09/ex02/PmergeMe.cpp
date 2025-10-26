#include "PmergeMe.hpp"

const std::regex PmergeMe::Number_FMT(FORMAT);

int PmergeMe::comparissons = 0;

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

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

void PmergeMe::performance_benchmark(std::vector<int>& input) {
    typedef std::chrono::high_resolution_clock Clock;
    typedef std::chrono::time_point<Clock> Time_point;
    typedef std::chrono::duration<double, std::micro> Microseconds;

    std::vector<int> vec_data;
    std::deque<int>  deq_data;
    int vec_comparissons, deq_comparissons;
    bool vec_status, deq_status;

    std::string status;

    PmergeMe::print("Before : ", input);

    Time_point vec_start = Clock::now();

    vec_data.insert(vec_data.end(), input.begin(), input.end());
    PmergeMe::ford_jhonson_sort(vec_data);

    Time_point vec_end = Clock::now();

    vec_comparissons = PmergeMe::comparissons;
    PmergeMe::comparissons = 0;

    Time_point deq_start = Clock::now();

    deq_data.insert(deq_data.end(), input.begin(), input.end());
    PmergeMe::ford_jhonson_sort(deq_data);

    Time_point deq_end = Clock::now();


    deq_comparissons = PmergeMe::comparissons;

    Microseconds vec_duration = (vec_end - vec_start);
    Microseconds deq_duration = (deq_end - deq_start);

    size_t vec_size = vec_data.size();
    size_t deq_size = deq_data.size();

    PmergeMe::print("After  : ", vec_data);

    PmergeMe::is_sorted<std::vector<int>&>(vec_data)
        ? vec_status = true
        : vec_status = false;

    PmergeMe::is_sorted<std::deque<int>&>(deq_data)
        ? deq_status = true
        : deq_status = false;

    PmergeMe::performance_report<Microseconds>(
        "std::vector<int>",
        vec_duration,
        vec_status,
        vec_size,
        vec_comparissons
    );

    PmergeMe::performance_report<Microseconds>(
        "std::deque<int>",
        deq_duration,
        deq_status,
        deq_size,
        deq_comparissons
    );

}

void PmergeMe::ford_jhonson_sort(std::vector<int>& data) {

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

    PmergeMe::ford_jhonson_sort(Main_chain);

    indexes = PmergeMe::updateIndexes<std::vector<int>&, Iterator>(Main_chain);

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
                return (a < b);
            }
        );
        Main_chain.insert(pos, value);
        indexes = PmergeMe::updateIndexes<std::vector<int>&, Iterator>(Main_chain);
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
                return (a < b);
            }
        );
        Main_chain.insert(pos, value);
        indexes = PmergeMe::updateIndexes<std::vector<int>&, Iterator>(Main_chain);
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
                    return (a < b);
                }
            );
            Main_chain.insert(pos, value);
            indexes = PmergeMe::updateIndexes<std::vector<int>&, Iterator>(Main_chain);
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
                return (a < b);
            }
        );
        Main_chain.insert(pos, odd_value);
    }

    data.assign(Main_chain.begin(), Main_chain.end());
}

void PmergeMe::ford_jhonson_sort(std::deque<int>& data) {

    typedef std::deque<int>::iterator Iterator;
    typedef std::unordered_map<int, Iterator> Index;
    typedef std::pair<Iterator, int>Element;

    std::deque<Element>Pend_chain;
    Index indexes;
    std::deque<int>Main_chain;

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

    PmergeMe::ford_jhonson_sort(Main_chain);

    indexes = PmergeMe::updateIndexes<std::deque<int>&, Iterator>(Main_chain);

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
                return (a < b);
            }
        );
        Main_chain.insert(pos, value);
        indexes = PmergeMe::updateIndexes<std::deque<int>&, Iterator>(Main_chain);
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
                return (a < b);
            }
        );
        Main_chain.insert(pos, value);
        indexes = PmergeMe::updateIndexes<std::deque<int>&, Iterator>(Main_chain);
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
                    return (a < b);
                }
            );
            Main_chain.insert(pos, value);
            indexes = PmergeMe::updateIndexes<std::deque<int>&, Iterator>(Main_chain);
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
                return (a < b);
            }
        );
        Main_chain.insert(pos, odd_value);
    }

    data.assign(Main_chain.begin(), Main_chain.end());
}
