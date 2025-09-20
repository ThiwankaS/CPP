#include <iostream>
#include <string>
#include <exception>
#include <ctime>

#include "Span.hpp"
#include "helper.hpp"

int main(void) {
    
    srand(time(NULL));
    Span mySpan(10);

    try {
        for(int i = 0; i < 10;i++){
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