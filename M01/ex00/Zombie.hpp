#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

/**
 * @brief The Orthodox Canonical Form in C++ involves defining 5 special member functions for a class.
 * Default Constructor
 * Parameterized Constructor
 * Copy Constructor
 * Assignment Operator
 * Destructor
*/

class Zombie {

    private:
        std::string _name;

    public:
        // Default constructor
        Zombie();

        // Parameterized Constructor
        Zombie(const std::string& name);

        // Copy Constructor
        Zombie(const Zombie& other);

        // Assignment Operator
        Zombie& operator=(const Zombie& other);

        // Destructor
        ~Zombie();

        // member function to announce themselves
        void announce (void);
};

#endif
