#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "test.hpp"

int main (void) {
	TEST_NAME("Test 01");
	LINE_DATA;
	Animal a1;
	a1.makeSound();

	TEST_NAME("Test 02");
	LINE_DATA;
	Animal a2("Lion");
	a2.makeSound();

	TEST_NAME("Test 03");
	LINE_DATA;
	Dog d1;
	d1.makeSound();

	TEST_NAME("Test 04");
	LINE_DATA;
	Dog d2("Bruuno");
	d2.makeSound();

	TEST_NAME("Test 05");
	LINE_DATA;
	Dog d3 = d2;
	d3.makeSound();

	TEST_NAME("Test 06");
	LINE_DATA;
	Animal* a4 = &d2;
	a4->makeSound();

    return (EXIT_SUCCESS);
}
