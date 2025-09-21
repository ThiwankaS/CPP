#include <iostream>
#include <exception>
#include <ctime>

#include "Span.hpp"
#include "helper.hpp"
#include "test.hpp"

constexpr size_t MAX_VALUES = 10;

int main(void) {

    test("example given in the subject document");
    LINE_DATA;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.print();
    NEW_LINE;

    std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
    std::cout << "longest span  : " << sp.longestSpan() << std::endl;

    NEW_LINE;

    srand(time(NULL));

    test("creating a new span with MAX_VALUE of integers");
    LINE_DATA;
    Span mySpan(MAX_VALUES);

    try {
        for(size_t i = 0; i < MAX_VALUES;i++){
            mySpan.addNumber(rand());
        }
        mySpan.print();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    NEW_LINE;

    test("trying add one more data, should result an exception");
    LINE_DATA;
    try{
        mySpan.addNumber(19880309);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    NEW_LINE;

    try {
        int shortSpan = mySpan.shortestSpan();
        std::cout << "shortest span : " << shortSpan << std::endl;

        int longSpan = mySpan.longestSpan();
        std::cout << "longest span  : " << longSpan << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    NEW_LINE;


    Span foo(2);

    test("trying to calculate span on empty span");
    LINE_DATA;
    try {
        int shortSpan = foo.shortestSpan();
        std::cout << "shortest span : " << shortSpan << std::endl;

        int longSpan = foo.longestSpan();
        std::cout << "longest span  : " << longSpan << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    NEW_LINE;

    try {
         foo.addNumber(10001);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    test("trying to calculate span on span with one element");
    LINE_DATA;
    try {
        int shortSpan = foo.shortestSpan();
        std::cout << "shortest span : " << shortSpan << std::endl;

        int longSpan = foo.longestSpan();
        std::cout << "longest span  : " << longSpan << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    NEW_LINE;

    try {
         foo.addNumber(20001);
         foo.print();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    test("trying to calculate span on span with two element");
    LINE_DATA;
    try {
        int shortSpan = foo.shortestSpan();
        std::cout << "shortest span : " << shortSpan << std::endl;

        int longSpan = foo.longestSpan();
        std::cout << "longest span  : " << longSpan << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    NEW_LINE;
    
    return (EXIT_SUCCESS);
}
