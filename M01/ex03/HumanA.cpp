#include "HumanA.hpp"

HumanA::HumanA ()
    : weapon(Weapon("default")){
    std::cout << "Default constructor called \n";
}

HumanA::HumanA (const std::string& name, const Weapon& weapon)
    : name(name), weapon(weapon) {
    std::cout << "Parameterized constructor called \n";
}

HumanA::HumanA (const HumanA& other)
    : name(other.name), weapon(other.weapon) {
    std::cout << "Copy constructor called \n";
}

HumanA& HumanA::operator=(const HumanA& other) {
    if (this != &other) {
        this->name   = other.name;
        this->weapon = other.weapon;
    }
    std::cout << "Assignment operator called \n";
    return (*this);
}

HumanA::~HumanA() {
    std::cout << "Default destructor called \n";
}

void HumanA::attack(void) {
    std::cout << name
              << " attacks with their "
              << weapon.getType()
              << "\n";
}
