#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), name("default") {
    setAttackDamage(30);
    std::cout << "DiamondTrap default constructor called.["
              << this->name
              << "]\n";
}

DiamondTrap::DiamondTrap(const std::string& _name)
: ClapTrap(_name + "_clap_name"), FragTrap(_name), ScavTrap(_name), name(_name) {
    setAttackDamage(30);
    std::cout << "DiamondTrap argument constructor called.["
              << this->name
              << "]\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), FragTrap(other), ScavTrap(other) {
    this->name = other.name;
    setAttackDamage(30);
    std::cout << "DiamondTrap copy constructor called.["
              << this->name
              << "]\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if(this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        this->name = other.name;
        setAttackDamage(30);
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called.["
              << this->name
              << "]\n";
}

void DiamondTrap::whoAmI(void) const {
    std::cout << "DiamondTrap::name will be :"
              <<this->name
              <<std::endl;
    std::cout << "ClapTrap::name will be :"
              <<ClapTrap::name
              <<std::endl;
}
