#include "Dog.hpp"

Dog::Dog()
: Animal() {
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const std::string& _name)
: Animal("Dog"), name(_name) {
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::Dog(const Dog& other)
: Animal(other), name(other.name) {
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if(this != &other) {
		Animal::operator=(other);
		this->name = other.name;
	}
	std::cout << "Dog assignment constructor called." << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Animal : type ["
			  << this->type
			  << "] name : "
			  << name
			  << " make sound : buh...buh.."
			  << std::endl;
}
