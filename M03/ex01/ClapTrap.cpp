#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: name ("default"), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "ClapTrap default constructor called.["
              << name
              << "]\n";
}

ClapTrap::ClapTrap(const std::string& name)
: name (name), hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "ClapTrap argument constructor called.["
              << name
              << "]\n";
}

ClapTrap::ClapTrap(const ClapTrap& other){
    std::cout << "ClapTrap copy constructor called.["
              << name
              << "]\n";
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assigment constructor called.["
              << name
              << "]\n";
    if (this != &other) {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap default destructor called.["
              << name
              << "]\n";
}

const std::string& ClapTrap::getName(void) {
    return (name);
}

unsigned int ClapTrap::getHitPoints(void) {
    return (hit_points);
}

unsigned int ClapTrap::getEnergyPoint(void) {
    return (energy_points);
}

unsigned int ClapTrap::getAttackDamage(void) {
    return (attack_damage);
}

void ClapTrap::setHitPoints(unsigned int amount) {
    this->hit_points = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount) {
    this->energy_points = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
    this->attack_damage = amount;
}

void ClapTrap::printStatus(void) {
    std::cout << "[STATUS] : Name {"
              << name
              << "} hit {"
              << hit_points
              << "} energy {"
              << energy_points
              << "} attack_damage {"
              << attack_damage
              << "}\n";
}

void ClapTrap::attack(const std::string& target) {

    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ClapTrap "
              << name
              << " attacks "
              << target
              << " causing "
              << attack_damage
              << " points of damage !\n";
        energy_points -= 1;
        return ;
    }

    std::cout << "ClapTrap "
              << name
              << " has no energy points or already destroyed !\n";
}

void ClapTrap::takeDamage(unsigned int amount) {

    if (hit_points == 0) {
        std::cout << "ClapTrap "
                  << name
                  << " already destroyed !\n";
        return ;
    }
    hit_points < amount ? hit_points = 0 : hit_points -= amount;
    std::cout << "ClapTrap "
              << name
              << " takes "
              << amount
              << " of damage !\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energy_points > 0)
    {
        energy_points -= 1;
        hit_points += amount;
        std::cout << "ClapTrap "
                  << name
                  << " repair itself !\n";
        return ;
    }

    std::cout << "ClapTrap "
              << name
              << " has no energy points or already destroyed !\n";

}
