#include "Zombie.hpp"

/**
 * @brief initializes an object with default values during the object’s
 * instantiation.
*/
Zombie::Zombie() : _name("name") {
    std::cout << this->_name
    << ": default constructor called \n";
}

/**
 * @brief initializes an object with specific values provided as arguments
 * during the object’s instantiation.
 * @param name the zombie's name
*/
Zombie::Zombie(const std::string& name) : _name(name) {
    std::cout << this->_name
    << ": parameterized constructor called\n";
}

/**
 * @brief nitializes a new object as a copy of an existing object.
 * Useful when passing an object by value or when we need to duplicate an object.
 * @param &other
*/
Zombie::Zombie(const Zombie& other) : _name(other._name) {
    std::cout << this->_name
    << ": copy constructor called \n";
}

/**
 * @brief assigns the value of one object to another already-existing object.
 * Need to handle deep copying and self-assignment.
 * @param const Zombie& other
 * @return Zombie&
*/
Zombie& Zombie::operator=(const Zombie& other) {
    if(this != &other) {
        this->_name = other._name;
    }
    std::cout << this->_name
    << ": assigment operator called \n";
    return (*this);
}

/**
 * @brief called when an object goes out of scope or is explicitly deleted.
 * Used to clean up resources such as memory or file handles.
 */
Zombie::~Zombie() {
    std::cout << this->_name
    << ": destructor called \n";
}

/**
 * @brief announce themselves in the format <name>: BraiiiiiiinnnzzzZ...
 * @param void
 * @return void
*/
void Zombie::announce(void) {
    std::cout << this->_name
    << ": BraiiiiiiinnnzzzZ...\n";
}
