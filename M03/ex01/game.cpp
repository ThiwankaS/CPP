#include "game.hpp"

void engage(ClapTrap& attacker, ClapTrap& target) {
    attacker.attack(target.getName());
    attacker.printStatus();
    target.takeDamage(attacker.getAttackDamage());
    target.printStatus();
}
