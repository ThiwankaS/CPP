#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap: public ClapTrap {

    private:


    public:
        FragTrap();
        FragTrap(const std::string& _name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        //class method
        void  highFivesGuys(void);
};

#endif
