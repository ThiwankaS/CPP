#include <iostream>
#include <exception>
#include <ctime>

#include "Span.hpp"
#include "helper.hpp"

constexpr size_t MAX_VALUES = 10001;

int main(void) {

    srand(time(NULL));
    Span mySpan(MAX_VALUES);

    try {
        for(size_t i = 0; i < MAX_VALUES;i++){
            mySpan.addNumber(rand());
        }
        mySpan.print();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        int shortSpan = mySpan.shortestSpan();
        std::cout << "shortest span : " << shortSpan << std::endl;

        int longSpan = mySpan.longestSpan();
        std::cout << "longest span  : " << longSpan << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (EXIT_SUCCESS);
}
