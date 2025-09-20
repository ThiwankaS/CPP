#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

#include "easyfind.hpp"

int main(void) {

    std::array<int, 6>marks = { 72, 86, 43, 98, 69, 82};
    print(marks);

    std::vector<int>numbers = { 10, 20, 30, 40, 50 };
    print(numbers);

    std::list<int>points = { 1, 2, 3, 4, 5 };
    print(points);
 
    return (EXIT_SUCCESS);
}
