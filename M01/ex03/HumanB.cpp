#include "HumanB.hpp"

/**
 * implementing parametized constructor, this will be the default constructor
 * because default constructor got removed
 */
HumanB::HumanB(const std::string& name)
	: name(name), weapon(nullptr) {
	std::cout << "Parameterized constructor [HumanB] called \n";
}

/**
 * implementing copy constructor
 */
HumanB::HumanB(const HumanB& other)
	: name(other.name), weapon(other.weapon) {
	std::cout << "Copy constructor [HumanB] called \n";
}

/**
 * implementing assignment operator
 */
HumanB& HumanB::operator=(const HumanB& other) {
	if(this != &other) {
		this->name   = other.name;
		this->weapon = other.weapon;
	}
	std::cout << "Assignment operator [HumanB] called \n";
	return (*this);
}

/**
 * implementing default destructor
 */
HumanB::~HumanB() {
	std::cout << "Default destructor [HumanB] called \n";
}

/**
 * @brief setWeapon function will the set the weapon value
 * of the caller
 * @param Weapon&
 * @return void
 */
void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

/**
 * @brief attack function will display a formated string base
 * on the "name" and the "wepon type" of the caller
 */
void HumanB::attack(void) {
	std::cout << name
              << " attacks with their ";
	if (weapon != nullptr) {
		std::cout << weapon->getType()
				  << "\n";
		return ;
	}
	std::cout << "\n";
}
