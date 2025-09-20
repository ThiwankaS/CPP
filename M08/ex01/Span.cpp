#include "Span.hpp"

Span::Span()
:N(1){}

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
    return (elements[1] - elements[0]);
}

int Span::longestSpan(void) {
    if(elements.size() <= 1)
        throw InvalidSpan();
    std::sort(elements.begin(), elements.end());
    return (elements[N-1] - elements[0]);
}

void Span::print(void) const {
    for(auto key : elements){
        std::cout << "elements :[" << key << "]\n";
    }
}
