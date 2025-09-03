#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap() {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap default constructor called.["
              << name
              << "]\n";
}

FragTrap::FragTrap(const std::string& _name)
: ClapTrap(_name) {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap argument constructor called.["
              << name
              << "]\n";
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other) {
    std::cout << "FragTrap copy constructor called.["
              << name
              << "]\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if(this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap assignment constructor called.["
              << name
              << "]\n";
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called.["
              << name
              << "]\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap Do you want a high five ?"
              << " Here you go.. ✋😄\n";
}
