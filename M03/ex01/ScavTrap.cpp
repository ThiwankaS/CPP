#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap() {
    is_in_gate_keeper_mode = false;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap default constructor called.["
              << name
              << "]\n";
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name) {
    is_in_gate_keeper_mode = false;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap argument constructor called.["
              << name
              << "]\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other) {
    is_in_gate_keeper_mode = other.is_in_gate_keeper_mode;
    std::cout << "ScavTrap copy constructor called.["
              << name
              << "]\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if(this != &other) {
        ClapTrap::operator=(other);
        is_in_gate_keeper_mode = other.is_in_gate_keeper_mode;
    }
    std::cout << "ScavTrap assignment constructor called.["
              << name
              << "]\n";
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called.["
              << name
              << "]\n";
}

void ScavTrap::guardGate(void) {
    if(!is_in_gate_keeper_mode) {
        is_in_gate_keeper_mode = true;
        std::cout << "ScavTrap "
                  << name
                  << " is now in Gate Keeper Mode !\n";
        return;
    }
    std::cout << "ScavTrap "
              << name
              << " is already in Gate Keeper Mode !\n";
}

void ScavTrap::attack(const std::string& target) {

    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ScavTrap "
              << name
              << " furiously attacks "
              << target
              << " causing "
              << attack_damage
              << " points of damage !\n";
        energy_points -= 1;
        return ;
    }

    std::cout << "ScavTrap "
              << name
              << " has no energy points or already destroyed !\n";
}
