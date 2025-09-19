#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {

	int type = rand() % 3;
	if(type == 0)
		return (new A);
	if(type == 1)
		return (new B);
	return (new C);
}

void identify(Base* p) {
	if(p != nullptr) {
		if (dynamic_cast<A*>(p))
			std::cout << "actual type of object (using pointer) : A " << std::endl;
		if (dynamic_cast<B*>(p))
			std::cout << "actual type of object (using pointer) : B " << std::endl;
		if (dynamic_cast<C*>(p))
			std::cout << "actual type of object (using pointer) : C " << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "actual type of object (using refernce) : A " << std::endl;
		(void)a;
	} catch (const std::exception& e) {
		//std::cerr << "Error @ A : " << e.what() << std::endl;
	}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "actual type of object (using refernce) : B " << std::endl;
		(void)b;
	} catch (const std::exception& e) {
		//std::cerr << "Error @ B : " << e.what() << std::endl;
	}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "actual type of object (using refernce) : C " << std::endl;
		(void)c;
	} catch (const std::exception& e) {
		//std::cerr << "Error @ C : " << e.what() << std::endl;
	}
}

int main (void) {

	srand(time(NULL));

	Base* ptr = generate();
	Base& ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;
    return (EXIT_SUCCESS);
}
