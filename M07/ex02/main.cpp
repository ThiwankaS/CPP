#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
    Array<int>numbers(5);
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    numbers[4] = 5;

    for(int i = 0;i < 5; i++){
        std::cout << "numbers[" << i << "] : " << numbers[i] << std::endl;
    }
    std::cout << "\n";

    numbers[4] = 100;

    for(int i = 0;i < 5; i++){
        std::cout << "numbers[" << i << "] : " << numbers[i] << std::endl;
    }
    std::cout << "\n";

    try {
        numbers[6] = 10;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        numbers[-1] = 10;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    Array<int>num;
    num = numbers;

    for(int i = 0;i < 5; i++){
        std::cout << "num[" << i << "] : " << num[i] << std::endl;
    }
    std::cout << "\n";

    numbers[4] = 10;

    for(int i = 0;i < 5; i++){
        std::cout << "num[" << i << "] : " << num[i] << std::endl;
    }
    std::cout << "\n";

    Array<float>distance;

    return 0;
}
