#include <iostream>

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "game.hpp"
#include "test.hpp"

int main (void) {

    test("test case 01");
    TEST_NAME("Creating an instance of ClapTrap with the name <Optimus>");
    LINE_DATA;
    ClapTrap C("Optimus");
    C.printStatus();
    LINE_DATA;

    test("test case 02");
    TEST_NAME("Creating an instance of ScavTrap with the name <Iornhide>");
    LINE_DATA;
    ScavTrap S("Iornhide");
    S.printStatus();
    LINE_DATA;

    test("test case 03");
    TEST_NAME("Creating an instance of FragTrap with the name <Bumblebee>");
    LINE_DATA;
    FragTrap F("Bumblebee");
    F.printStatus();
    LINE_DATA;

    test("test case 04");
    TEST_NAME("Creating an instance of DiamondTrap with default constructor");
    LINE_DATA;
    DiamondTrap D1;
    D1.printStatus();
    engage(D1, C);
    LINE_DATA;

    test("test case 05");
    TEST_NAME("Creating an instance of DiamondTrap with the name <Sweeper>");
    LINE_DATA;
    DiamondTrap D2("Sweeper");
    D2.printStatus();
    engage(D2, S);
    LINE_DATA;

    test("test case 06");
    TEST_NAME("Creating an instance of DiamondTrap using assignment constructor");
    LINE_DATA;
    DiamondTrap D3 = D2;
    D3.printStatus();
    engage(D3, F);
    LINE_DATA;

    test("test case 07");
    TEST_NAME("<Sweeper> calling whoAmI");
    LINE_DATA;
    D2.whoAmI();
    LINE_DATA;

    return (EXIT_SUCCESS);
}
