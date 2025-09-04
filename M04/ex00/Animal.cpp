#include "Animal.hpp"

Animal::Animal()
: type("defaut") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const std::string& _type)
: type(_type) {
	std::cout << "Animal argument constructor called." << std::endl;
}

Animal::Animal(const Animal& other)
: type(other.type) {
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if(this != &other) {
		Animal(other.type);
	}
	std::cout << "Animal assigment constructor called." << std::endl;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "Animal : type ["
			  << this->type
			  << "] make wrong sound"
			  << std::endl;
}
