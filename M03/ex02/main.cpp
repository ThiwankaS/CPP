#include <iostream>

#include "FragTrap.hpp"
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
    TEST_NAME("Creating a FragTrap instance with the name <Ratchet>");
    FragTrap C("Ratchet");
    C.printStatus();
    NEW_LINE;

    test("test case 04");
    TEST_NAME("<Starscreamer> attacking <Ratchet> for 05 times");
    for(int i = 0; i < 5; i++) {
        engage(A, C);
        NEW_LINE;
    }

    test("test case 05");
    TEST_NAME("<Starscreamer> calling beRepaired");
    A.beRepaired(20);
    A.printStatus();
    B.printStatus();
    NEW_LINE;

    test("test case 06");
    TEST_NAME("<Ratchet> attacking <Starscreamer> for 02 times");
    for(int i = 0; i < 3; i++) {
        engage(B, A);
        NEW_LINE;
    }

    test("test case 07");
    TEST_NAME("<Ratchet> giving high five");
    C.highFivesGuys();
    NEW_LINE;

    test("test case 08");
    TEST_NAME("Creating a ClapTrap base pointer and assing new instance of FragTrap");
    ClapTrap* ptr = new FragTrap("Hound");
    ptr->printStatus();
    delete ptr;
    NEW_LINE;

    return (EXIT_SUCCESS);
}
