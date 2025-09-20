#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <forward_list>

#include "easyfind.hpp"
#include "test.hpp"

int main(void) {

    test("creating an array and filling with data");
    LINE_DATA;
    std::array<int, 6>marks = { 72, 86, 43, 98, 69, 82};
    print(marks);
    std::cout << "\n";

    test("creating a vector and filling with data");
    LINE_DATA;
    std::vector<int>numbers = { 10, 20, 30, 40, 50 };
    print(numbers);
    std::cout << "\n";

    test("creating a double linked list and filling with data");
    LINE_DATA;
    std::list<int>points = { 1, 2, 3, 4, 5 };
    print(points);
    std::cout << "\n";

    test("creating a single liked list and filling with data");
    LINE_DATA;
    std::forward_list<int>rooms = { 201, 202, 203, 204, 205, 206, 207, 208, 209, 210 };
    print(rooms);
    std::cout << "\n";

    test("attemp to find an existing data in array");
    LINE_DATA;
    try {
        int key = easyfind(marks, 69);
        std::cout << " key : " << key << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";
 
    test("attemp to find a non existing data in array");
    LINE_DATA;
    try {
        int key = easyfind(marks, 100);
        std::cout << " key : " << key << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";

    test("attemp to find an existing data in vector");
    LINE_DATA;
    try {
        int key = easyfind(numbers, 20);
        std::cout << " key : " << key << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";
 
    test("attemp to find a non existing data in vector");
    LINE_DATA;
    try {
        int key = easyfind(numbers, 65);
        std::cout << " key : " << key << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";

    test("attemp to find an existing data in list");
    LINE_DATA;
    try {
        int key = easyfind(points, 1);
        std::cout << " key : " << key << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";
 
    test("attemp to find a non existing data in list");
    LINE_DATA;
    try {
        int key = easyfind(points, 10);
        std::cout << " key : " << key << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";

    test("attemp to find an existing data in forward_list");
    LINE_DATA;
    try {
        int key = easyfind(rooms, 205);
        std::cout << " key : " << key << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";
 
    test("attemp to find a non existing data in forward_list");
    LINE_DATA;
    try {
        int key = easyfind(rooms, 301);
        std::cout << " key : " << key << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";

    return (EXIT_SUCCESS);
}
