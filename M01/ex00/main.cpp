#include <iostream>

#include "Zombie.hpp"
#include "utilities.hpp"
#include "test.hpp"

int main(void) {
    /**
     * creating a new instance of Zombie'e with out any parameter,
     * idea is to demonstrate automatic invokation of default constructor
     * and destructor
    */
    test("test case 01");
    TEST_NAME("Default construtor behavior");
    LINE_DATA;
    {
        std::cout << "insdie new scope !\n";
        LINE_DATA;
        Zombie z1 = Zombie();
        z1.announce();
        LINE_DATA;
    }
    std::cout << "outside of the scope !\n";
    LINE_DATA;

    /**
     * creating another instance of Zombie with a name calling the parameterized
     * constructor, here is also the idea to demostrate automatic invokation of default constructor
     * and destructor
    */

    test("test case 02");
    TEST_NAME("Parameterized constructor behavior");
    LINE_DATA;
    {
        std::cout << "insdie new scope !\n";
        LINE_DATA;
        Zombie z2 = Zombie("Rick Grimes");
        z2.announce();
        LINE_DATA;
    }
    std::cout << "outside of the scope !\n";
    LINE_DATA;

    /**
     * creating an instance of Zombie class with a name in Heap memory using
     * Zombie* newZombie(std::string name) function
     * idea is to demostrate the behavior consturctor and destructor
    */
    test("test case 03");
    TEST_NAME("Create an instance on heap memory");
    Zombie *z3;
    LINE_DATA;
    {
        std::cout << "insdie new scope !\n";
        LINE_DATA;
        z3 = newZombie("Jill Valentine");
        z3->announce();
        LINE_DATA;
    }
    std::cout << "outside of the scope !\n";
    LINE_DATA;
    std::cout << "explicitly calling destructor...\n";
    LINE_DATA;
    delete z3;

    /**
     * creating an intance of Zombie using the function
     * void randomChump( std::string name )
     * the instance will creat on the stack and it will anounce the name by itself
     * agin the idea is to demostrate constructor and destructor calling
    */
    test("test case 04");
    TEST_NAME("Create an instance on stack memory");
    LINE_DATA;
    {
        std::cout << "insdie new scope !\n";
        LINE_DATA;
        randomChump("Brainy Allegheny");
        LINE_DATA;
    }
    std::cout << "outside of the scope !\n";
    LINE_DATA;
    return (0);
}
