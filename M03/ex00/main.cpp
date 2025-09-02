#include <iostream>


#include "ClapTrap.hpp"
#include "game.hpp"
#include "test.hpp"

int main (void) {

    test("test case 01");
    TEST_NAME("Creating a ClapTrap instance with the name <Megatron>");
    ClapTrap A("Megatron");
    A.printStatus();
    NEW_LINE;

    test("test case 02");
    TEST_NAME("Creating a ClapTrap instance with the name <Optimus>");
    ClapTrap B("Optimus");
    B.printStatus();
    NEW_LINE;

    test("test case 03");
    TEST_NAME("<Megatron> attacking <Optimus> for 05 times");
    for(int i = 0; i < 5; i++) {
        engage(A, B);
        NEW_LINE;
    }

    test("test case 04");
    TEST_NAME("<Megatron> calling beRepaired");
    A.beRepaired(5);
    A.printStatus();
    B.printStatus();
    NEW_LINE;

    test("test case 05");
    TEST_NAME("<Optimus> update attack damage to 05");
    B.setAttackDamage(5);
    A.printStatus();
    B.printStatus();
    NEW_LINE;

    test("test case 06");
    TEST_NAME("<Optimus> attacking <Megatron> for 05 times");
    for(int i = 0; i < 5; i++) {
        engage(B, A);
        NEW_LINE;
    }

    return (EXIT_SUCCESS);
}
