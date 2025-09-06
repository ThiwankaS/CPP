#include "AAnimal.hpp"

AAnimal::AAnimal()
: type("defaut") {
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(const std::string& _type)
: type(_type) {
	std::cout << "AAnimal argument constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
: type(other.type) {
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if(this != &other) {
		this->type = other.type;
	}
	std::cout << "AAnimal assigment constructor called." << std::endl;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called." << std::endl;
}
