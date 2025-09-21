#include "Span.hpp"

Span::Span()
:N(0){}

Span::Span(const size_t size)
:N(size){}

Span::Span(const Span& other) {
    this->N = other.N;
    this->elements = other.elements;
}

Span& Span::operator=(const Span& other) {
    if(this != &other) {
        this->N = other.N;
        this->elements = other.elements;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int input) {
    if(elements.size() >= N) {
        throw MaxSizeExceeded();
    }
    elements.push_back(input);
}

int Span::shortestSpan(void) {
    if(elements.size() <= 1)
        throw InvalidSpan();
    std::sort(elements.begin(), elements.end());
    int best = std::numeric_limits<int>::max(), diff = std::numeric_limits<int>::max();
    for(size_t i = 1; i < elements.size();i++) {
        diff = elements[i] - elements[i - 1];
        if (diff == 0)
            return (0);
        if(diff < best)
            best = diff;
    }
    return (best);
}

int Span::longestSpan(void) {
    if(elements.size() <= 1)
        throw InvalidSpan();
    std::sort(elements.begin(), elements.end());
    auto result = std::minmax_element(elements.begin(), elements.end());
    return (*result.second - *result.first);
}

void Span::print(void) {
    std::sort(elements.begin(), elements.end());
    for(auto key : elements){
        std::cout << "elements :[" << key << "]\n";
    }
}
