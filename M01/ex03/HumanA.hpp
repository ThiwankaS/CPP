#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>

#include "Weapon.hpp"

class HumanA {

    private:
        std::string name;
        Weapon&      weapon;

    public:
        // default constructor
        HumanA();
        // parameterized constructor
        HumanA(const std::string& name, const Weapon& weapon);
        // copy constructctor
        HumanA(const HumanA& other);
        // assignment operator
        HumanA& operator=(const HumanA& other);
        // default destructor
        ~HumanA();
        // calss methods
        void attack(void);
};

#endif
