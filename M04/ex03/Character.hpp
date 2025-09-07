#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define SIZE 4

class Character : public ICharacter {

    private:
        std::string name;
        AMateria* inventory[SIZE];

    public:
        Character();
        Character(const std::string& _name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();

        std::string const & getName() const override;
        void equip(AMateria* m) override;
        void unequip(int idx) override;
        void use(int idx, ICharacter& target) override;
};

#endif
