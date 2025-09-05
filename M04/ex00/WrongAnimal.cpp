#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: type("defaut") {
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& _type)
: type(_type) {
	std::cout << "WrongAnimal argument constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
: type(other.type) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if(this != &other) {
		WrongAnimal(other.type);
	}
	std::cout << "WrongAnimal assigment constructor called." << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal : type ["
			  << this->type
			  << "] make wrong sound"
			  << std::endl;
}
