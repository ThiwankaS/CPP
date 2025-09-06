#include <iostream>
#include <string>

#include "Brain.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "test.hpp"

int main (void) {

	test("test 01");
	TEST_NAME("Creating an array of base class pointers");
	LINE_DATA;
	AAnimal *all[10];

	test("test 02");
	TEST_NAME("Allocating first half for Dog objects");
	LINE_DATA;
	for(int i = 0; i < 5; i++) {
		all[i] = new Dog("Snowy");
	}

	test("test 03");
	TEST_NAME("Allocating second half for Cat objects");
	LINE_DATA;
	for(int i = 5; i < 10; i++) {
		all[i] = new Cat("Fluffy");
	}

	test("test 04");
	TEST_NAME("Call makesound() on each object using base class pointer");
	LINE_DATA;
	for(int i = 0; i < 10; i++){
		all[i]->makeSound();
	}

	test("test 05");
	TEST_NAME("Allocating memory on the heap for Dog object and check deep copy");
	LINE_DATA;
	Dog d0("Lilly");
	Dog *d1 = new Dog("Blacky");
	Dog *d2 = new Dog(d0);
	LINE_DATA;
	delete d1;
	delete d2;

	test("test 06");
	TEST_NAME("Allocating memory on the heap for Cat object and check deep copy");
	LINE_DATA;
	Cat c0("Pinky");
	Cat *c1 = new Cat("Grumpy");
	Cat *c2 = new Cat(c0);
	LINE_DATA;
	delete c1;
	delete c2;

	test("test 02");
	TEST_NAME("Freeing allocated memory");
	LINE_DATA;
	for(int i = 0; i < 10; i++) {
		delete  all[i];
	}
    return (EXIT_SUCCESS);
}
