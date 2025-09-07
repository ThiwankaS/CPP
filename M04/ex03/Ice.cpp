#include "Ice.hpp"

Ice::Ice()
: AMateria("ice") {
    //std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice& other)
: AMateria(other) {
    //std::cout << "Ice copy constructor called." << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    if(this != &other) {
        AMateria::operator=(other);
    }
    //std::cout << "Ice assigment operator called." << std::endl;
    return (*this);
}

Ice::~Ice() {
    //std::cout << "Ice destructor called." << std::endl;
}

AMateria* Ice::clone(void) const {
    return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at "
              << target.getName()
              << " *"
              << std::endl;
}
