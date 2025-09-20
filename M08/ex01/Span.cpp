#include "Span.hpp"

Span::Span()
:N(1), element_count(0) {}

Span::Span(const size_t size)
:N(size), element_count(0) {}

Span::Span(const Span& other) {
    this->N = other.N;
    this->elements = other.elements;
    this->element_count = other.element_count;
}

Span& Span::operator=(const Span& other) {
    if(this != &other) {
        this->N = other.N;
        this->elements = other.elements;
        this->element_count = other.element_count;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int input) {
    if(element_count >= N) {
        throw MaxSizeExceeded();
    }
    elements.push_back(input);
    element_count++;
}

int Span::shortestSpan(void) {
    if(element_count <= 1)
        throw InvalidSpan();
    std::sort(elements.begin(), elements.end());
    return (elements[1] - elements[0]);
}

int Span::longestSpan(void) {
    if(element_count <= 1)
        throw InvalidSpan();
    std::sort(elements.begin(), elements.end());
    return (elements[N-1] - elements[0]);
}

void Span::print(void) const {
    for(auto key : elements){
        std::cout << "elements :[" << key << "]\n";
    }
}