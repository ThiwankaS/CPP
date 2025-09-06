#include "Ice.hpp"

Ice::Ice()
: AMateria("deafult"), Character() {
    std::cout << "Ice default constructor called." << std::endl;   
}

AMateria* Ice::clone(void) const {
    return (new Ice(*this));
}