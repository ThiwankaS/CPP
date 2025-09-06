#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("Cat"), name("default") {
    std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const std::string& _name)
: WrongAnimal("Cat"), name(_name) {
    std::cout << "WrongCat argument constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
: WrongAnimal(other), name(other.name) {
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if(this != &other) {
        WrongAnimal::operator=(other);
        this->name = other.name;
    }
    std::cout << "WrongCat assignment operator called." << std::endl;
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "WrongAnimal : type ["
			  << this->type
			  << "] name : "
			  << name
			  << " make sound : meow... meow..."
			  << std::endl;
}
