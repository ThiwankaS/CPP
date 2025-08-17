#include "Weapon.hpp"

/**
 * implementaion of deafult destrcutor
*/
Weapon::Weapon () {
    std::cout << "Default constuctor called \n";
}

/**
 * implementation of parameterized constructor
*/
Weapon::Weapon (const std::string& param) : type(param) {
    std::cout << "Parameterized constructor called \n";
}

/**
 * implementation of copy constructor
*/
Weapon::Weapon (const Weapon& other) : type(other.type) {
    std::cout << "Copy constructor called \n";
}

/**
 * implementation of assignment operator
*/
Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Assigment operator called \n";
    return (*this);
}

/**
 * implementaion of default destructor
*/
Weapon:: ~Weapon() {
    std::cout << "Default destructor called \n";
}

/**
 * access member variable "type" value
*/
const std::string& Weapon::getType(void) {

    std::string& ref = type;
    return (ref);
}

/**
 * update the member variable "type" value
*/
void Weapon::setType(const std::string& param) {

    this->type = param;
}
