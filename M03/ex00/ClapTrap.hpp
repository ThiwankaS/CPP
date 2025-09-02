#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

    private:
        std::string name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;

    public:
        //constructors & destructors
        ClapTrap();
        ClapTrap(const std::string& _name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap &other);
        ~ClapTrap();

        //getters
        const std::string& getName(void);
        unsigned int getHitPoints(void);
        unsigned int getEnergyPoint(void);
        unsigned int getAttackDamage(void);

        //setters
        void setHitPoints(unsigned int amount);
        void setEnergyPoints(unsigned int amount);
        void setAttackDamage(unsigned int amount);

        //class methods
        void printStatus(void);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
