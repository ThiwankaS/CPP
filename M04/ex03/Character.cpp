#include "Character.hpp"

Character::Character() 
: name("default") {
    for(int i = 0; i < SIZE; i++) {
        inventory[i] = NULL;
    }
    std::cout << "Character default constructor called." << std::endl;
}

Character::Character(const std::string& _name)
: name(_name) {
    for(int i = 0; i < SIZE; i++) {
        inventory[i] = NULL;
    }
    std::cout << "Character argument constructor called." << std::endl;
}

Character::Character(const Character& other) 
: name(other.name) {
     for(int i = 0; i < SIZE; i++) {
        inventory[i] = other.inventory[i]->clone();
    }
    std::cout << "Character copy constructor called." << std::endl;
}

Character& Character::operator=(const Character& other) {
    if(this != &other) {
        for(int i = 0; i < SIZE; i++) {
            inventory[i] = other.inventory[i];
        }
    }
    std::cout << "Character assignment constructor called." << std::endl;
    return (*this);
}

Character::~Character() {
    for(int i = 0; i < SIZE; i++) {
        delete inventory[i];
    }
    std::cout << "Character destructor called." << std::endl;
}