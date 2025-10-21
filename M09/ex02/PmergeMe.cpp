#include "PmergeMe.hpp"

const std::regex PmergeMe::Number_FMT(FORMAT);

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
