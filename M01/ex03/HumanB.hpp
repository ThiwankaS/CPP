#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>

#include "Weapon.hpp"

class HumanB {

	private:
		std::string name;
		Weapon      *weapon;

	public:
		// remove default constructor
		HumanB() = delete;
		// parameterized constructors
		HumanB(const std::string& name);
		// copy constructor
		HumanB(const HumanB& other);
		// assignment operator
		HumanB& operator=(const HumanB& other);
		// default destructor
		~HumanB();

		//class methods
		void attack(void);
		void setWeapon(Weapon& weapon);
};

#endif
