#include <iostream>

#include "Array.hpp"
#include "test.hpp"

int main(void)
{
    test("creating an array of integers...");
    LINE_DATA;
    Array<int>numbers(5);
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    numbers[4] = 5;

    for(int i = 0;i < 5; i++){
        std::cout << "numbers[" << i << "] : " << numbers[i] << std::endl;
    }
    NEW_LINE;

    test("indexes can be access using subscipt operator");
    LINE_DATA;
    numbers[4] = 100;

    for(int i = 0;i < 5; i++){
        std::cout << "numbers[" << i << "] : " << numbers[i] << std::endl;
    }
    std::cout << "\n";
    NEW_LINE;

    test("invalid index access will throw an exception");
    LINE_DATA;
    try {
        numbers[6] = 10;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    NEW_LINE;

    test("invalid index access will throw an exception");
    LINE_DATA;
    try {
        numbers[-1] = 10;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    NEW_LINE;

    test("new array can be create using assigment operator");
    LINE_DATA;
    Array<int>num;
    num = numbers;

    for(int i = 0;i < 5; i++){
        std::cout << "num[" << i << "] : " << num[i] << std::endl;
    }
    NEW_LINE;

    test("constructors cerate seperate array");
    LINE_DATA;
    numbers[4] = 10;

    for(int i = 0;i < 5; i++){
        std::cout << "num[" << i << "] : " << num[i] << std::endl;
    }
    NEW_LINE;
    for(int i = 0;i < 5; i++){
        std::cout << "numbers[" << i << "] : " << numbers[i] << std::endl;
    }
    std::cout << "\n";
    NEW_LINE;

    test("copy constructors can cerate an array");
    LINE_DATA;
    Array<int>points(num);

    for(int i = 0;i < 5; i++){
        std::cout << "points[" << i << "] : " << points[i] << std::endl;
    }

    Array<float>distance;
    Array<std::string>words;

    return 0;
}
