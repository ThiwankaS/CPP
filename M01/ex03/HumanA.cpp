#include "HumanA.hpp"

/**
 * implementing parametized constructor, this will be the default constructor
 * because default constructor got removed
 */
HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name(name), weapon(weapon) {
    std::cout << "Parameterized constructor [HumanA] called \n";
}

/**
 * implementing copy constructor
 */
HumanA::HumanA (const HumanA& other)
    : name(other.name), weapon(other.weapon) {
    std::cout << "Copy constructor [HumanA] called \n";
}

/**
 * implementing assignment operator
 */
HumanA& HumanA::operator=(const HumanA& other) {
    if (this != &other) {
        this->name   = other.name;
        this->weapon = other.weapon;
    }
    std::cout << "Assignment operator [HumanA] called \n";
    return (*this);
}

/**
 * implementing default destructor
 */
HumanA::~HumanA() {
    std::cout << "Default destructor [HumanA] called \n";
}

/**
 * @brief attack function will display a formated string base
 * on the "name" and the "wepon type" of the caller
 */
void HumanA::attack(void) {
    std::cout << name
              << " attacks with their "
              << weapon.getType()
              << "\n";
}
