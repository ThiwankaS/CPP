#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "test.hpp"

int main (void) {

	test("test 01");
	TEST_NAME("Creating an instance of Aimal using default constructor");
	LINE_DATA;
	Animal a1;
	a1.makeSound();

	test("test 02");
	TEST_NAME("Creating an instance of Animal using argument constructor");
	LINE_DATA;
	Animal a2("Lion");
	a2.makeSound();

	test("test 03");
	TEST_NAME("Creating an instance of Dog default constructor");
	LINE_DATA;
	Dog d1;
	d1.makeSound();

	test("test 04");
	TEST_NAME("Creating an instance of Dog using argument constructor");
	LINE_DATA;
	Dog d2("Brown");
	d2.makeSound();

	test("test 05");
	TEST_NAME("Creating an instance of Dog using assigment constructor");
	LINE_DATA;
	Dog d3 = d2;
	d3.makeSound();

	test("case 06");
	TEST_NAME("Creating another instance of Dog and assign to Base class pointer");
	LINE_DATA;
	Animal* a4 = &d2;
	a4->makeSound();

	test("case 07");
	TEST_NAME("Creating another instance of Dog on the heap and assign to Base class pointer");
	LINE_DATA;
	Animal* a5 = new Dog("Scooby");
	a5->makeSound();

    return (EXIT_SUCCESS);
}
