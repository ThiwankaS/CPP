#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>

#include "Weapon.hpp"

class HumanA {

    private:
        std::string name;
        Weapon&     weapon;

    public:
        // removing default constructor
        HumanA() = delete;
        // parameterized constructor
        HumanA(const std::string& name, Weapon& weapon);
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
