#include <iostream>


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "game.hpp"
#include "test.hpp"

int main (void) {

    test("test case 01");
    TEST_NAME("Creating a ClapTrap instance with the name <Starscreamer>");
    ClapTrap A("Starscreamer");
    A.printStatus();
    NEW_LINE;

    test("test case 02");
    TEST_NAME("Creating a ScavTrap instance with the name <Bumblebee>");
    ScavTrap B("Bumblebee");
    B.printStatus();
    NEW_LINE;

    test("test case 03");
    TEST_NAME("<Starscreamer> attacking <Megatron> for 05 times");
    for(int i = 0; i < 5; i++) {
        engage(A, B);
        NEW_LINE;
    }

    test("test case 04");
    TEST_NAME("<Starscreamer> calling beRepaired");
    A.beRepaired(20);
    A.printStatus();
    B.printStatus();
    NEW_LINE;

    test("test case 05");
    TEST_NAME("<Bumblebee> attacking <Starscreamer> for 02 times");
    for(int i = 0; i < 3; i++) {
        engage(B, A);
        NEW_LINE;
    }

    test("test case 06");
    TEST_NAME("<Bumblebee> status changed to Gate Keeper Mode");
    B.guardGate();
    NEW_LINE;

    return (EXIT_SUCCESS);
}
