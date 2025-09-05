#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
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

	test("test 08");
	TEST_NAME("Creating an instance of Cat default constructor");
	LINE_DATA;
	Cat c1;
	c1.makeSound();

	test("test 09");
	TEST_NAME("Creating an instance of Cat using argument constructor");
	LINE_DATA;
	Cat c2("Chubby");
	c2.makeSound();

	test("test 10");
	TEST_NAME("Creating an instance of Cat using assigment constructor");
	LINE_DATA;
	Cat c3 = c2;
	c3.makeSound();

	test("case 11");
	TEST_NAME("Creating another instance of Cat and assign to Base class pointer");
	LINE_DATA;
	Animal* a6 = &c2;
	a6->makeSound();

	test("case 12");
	TEST_NAME("Creating another instance of Cat on the heap and assign to Base class pointer");
	LINE_DATA;
	Animal* a7 = new Cat("Cheecky");
	a7->makeSound();

	test("test 13");
	TEST_NAME("Creating an instance of Wrong Aimal using default constructor");
	LINE_DATA;
	WrongAnimal wa1;
	wa1.makeSound();

	test("test 14");
	TEST_NAME("Creating an instance of Wrong Animal using argument constructor");
	LINE_DATA;
	WrongAnimal wa2("Unicorn");
	wa2.makeSound();

	test("test 15");
	TEST_NAME("Creating an instance of Wrong Cat with default constructor");
	LINE_DATA;
	WrongCat wc1;
	wc1.makeSound();

	test("test 16");
	TEST_NAME("Creating an instance of Wrong Cat with argument constructor");
	LINE_DATA;
	WrongCat wc2("Fluffy");
	wc2.makeSound();

	test("test 17");
	TEST_NAME("Creating an instance of Wrong Cat with assigment constructor");
	LINE_DATA;
	WrongCat wc3 = wc2;
	wc3.makeSound();

	test("test 18");
	TEST_NAME("Creating a base class pointer and instace of Wrong Cat on heap");
	LINE_DATA;
	WrongAnimal *wa3 = new WrongCat("Shadow");
	wa3->makeSound();

    return (EXIT_SUCCESS);
}
