#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <limits>

class Span {

    private:
        size_t N;
        std::vector<int>elements;

    public:
        Span();
        Span(const size_t size);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        struct MaxSizeExceeded : public std::exception {
            virtual const char* what() const noexcept {
                return "Maximum no of elements exceeded!";
            }
        };

        struct InvalidSpan : public std::exception {
            virtual const char* what() const noexcept {
                return "Span can not be calculated!";
            }
        };

        void addNumber(int input);
        int shortestSpan(void);
        int longestSpan(void);
        void print(void);

        template<typename Iter>
        void addRange(Iter begin, Iter end) {
            if((elements.size() + std::distance(begin, end)) > N)
                throw MaxSizeExceeded();
            elements.insert(elements.end(), begin, end);
        }
};
