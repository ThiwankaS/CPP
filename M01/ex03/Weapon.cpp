#include "Weapon.hpp"

/**
 * implementaion of deafult destrcutor
*/
Weapon::Weapon () {
    std::cout << "Default constuctor [Weapon] called \n";
}

/**
 * implementation of parameterized constructor
*/
Weapon::Weapon (const std::string& param) : type(param) {
    std::cout << "Parameterized constructor [Weapon] called \n";
}

/**
 * implementation of copy constructor
*/
Weapon::Weapon (const Weapon& other) : type(other.type) {
    std::cout << "Copy constructor [Weapon] called \n";
}

/**
 * implementation of assignment operator
*/
Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Assigment operator [Weapon] called \n";
    return (*this);
}

/**
 * implementaion of default destructor
*/
Weapon:: ~Weapon() {
    std::cout << "Default destructor [Weapon] called \n";
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
