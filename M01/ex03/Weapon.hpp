#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

    private:
        std::string type;

    public:
        // default constructor
        Weapon();
        // parameterized constructor
        Weapon(const std::string& param);
        // copy constructor
        Weapon(const Weapon& other);
        // assigment operator
        Weapon& operator=(const Weapon& other);
        // default destructor
        ~Weapon();

        void setType(const std::string& param);
        const std::string& getType(void);
};

#endif
