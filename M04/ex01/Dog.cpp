#include "Dog.hpp"

Dog::Dog()
: Animal("Dog"), name("default") {
	brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const std::string& _name)
: Animal("Dog"), name(_name) {
	brain = new Brain();
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::Dog(const Dog& other)
: Animal(other), name(other.name) {
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if(this != &other) {
		Animal::operator=(other);
		this->brain = other.brain;
		this->name = other.name;
	}
	std::cout << "Dog assignment constructor called." << std::endl;
	return (*this);
}

Dog::~Dog() {
	delete brain;
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

void Dog::brainSurgery(void) const {
	this->brain->showAllIdeas();
}

void Dog::giveIdea(const std::string& idea) {
	this->brain->setIdeas(idea);
}
