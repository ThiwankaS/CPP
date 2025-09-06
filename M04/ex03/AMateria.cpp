#include "AMateria.hpp"

AMateria::AMateria() 
: _type("deafult"){
    std::cout << "AMeteria default constructor called." << std::endl;
}

AMateria::AMateria(const std::string& type)
: _type(type) {
    std::cout << "AMeteria argument constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& other)
: _type(other._type) {
    std::cout<< "AMeteria copy constructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if(this != &other) {
        _type = other._type;
    }
    std::cout << "AMeteria assignment constructor called." << std::endl;
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "AMeteria destructor called." << std::endl;
}

std::string const & AMateria::getType(void) {
    return (this->_type);
}

void AMateria::use(ICharacter& target) {
    (void) target;
    std::cout << "Doing nothing in use()" << std::endl;
}