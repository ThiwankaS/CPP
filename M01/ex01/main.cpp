#include <iostream>

#include "Zombie.hpp"
#include "utilities.hpp"
#include "test.hpp"

int main(void) {

    test("test case 01");
    TEST_NAME("Creating 05 Zombie objects with the Name Rick Grimes");
    LINE_DATA;
    Zombie *zombies = zombieHorde(5,"Rick Grimes");
    LINE_DATA;

    test("test case 02");
    TEST_NAME("announce() method call on each object in the array");
    LINE_DATA;
    for(int i = 0; i < 5; i++) {
        std::cout << "zombies[" << i << "] : ";
        (zombies + i)->announce();
    }
    LINE_DATA;

    test("test case 03");
    TEST_NAME("Releasing allocated memory for each object");
    LINE_DATA;
    delete [] zombies;
    LINE_DATA;

    return (0);
}
