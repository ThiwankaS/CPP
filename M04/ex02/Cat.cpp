#include "Cat.hpp"

Cat::Cat()
: AAnimal("Cat"), name("default") {
    brain = new Brain();
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const std::string& _name)
: AAnimal("Cat"), name(_name) {
    brain = new Brain();
    std::cout << "Cat argument constructor called." << std::endl;
}

Cat::Cat(const Cat& other)
: AAnimal(other), name(other.name) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if(this != &other) {
        AAnimal::operator=(other);
        brain = new Brain(*other.brain);
        this->name = other.name;
    }
    std::cout << "Cat assignment operator called." << std::endl;
    return (*this);
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "AAnimal : type ["
			  << this->type
			  << "] name : "
			  << name
			  << " make sound : meow... meow..."
			  << std::endl;
}
