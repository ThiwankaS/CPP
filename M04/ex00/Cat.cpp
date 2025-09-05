#include "Cat.hpp"

Cat::Cat()
: Animal("Cat"), name("default") {
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const std::string& _name)
: Animal("Cat"), name(_name) {
    std::cout << "Cat argument constructor called." << std::endl;
}

Cat::Cat(const Cat& other)
: Animal(other), name(other.name) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if(this != &other) {
        Animal::operator=(other);
        this->name = other.name;
    }
    std::cout << "Cat assignment operator called." << std::endl;
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Animal : type ["
			  << this->type
			  << "] name : "
			  << name
			  << " make sound : meow... meow..."
			  << std::endl;
}
