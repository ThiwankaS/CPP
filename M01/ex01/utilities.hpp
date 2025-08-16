#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <iostream>

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif
