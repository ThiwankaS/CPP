#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {

    private:
        bool is_in_gate_keeper_mode;

    public:
        //constructors & destructors
        ScavTrap();
        ScavTrap(const std::string& _name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        //class methods
        void guardGate(void);
        void attack(const std::string& target) override;
};

#endif
