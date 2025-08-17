#include <iostream>
#include <string>

#include "test.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {

	test("test case 01");
	TEST_NAME("Creating an instance of HumanA class");
	LINE_DATA;
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob ("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
	LINE_DATA;

	test("test case 02");
	TEST_NAME("Creating an instance of HumanB class");
	LINE_DATA;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim ("Jim");
		jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
	LINE_DATA;

    return (0);
}
