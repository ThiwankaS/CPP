#ifndef ICE_HPP
#define ICE_HPP

#include "Character.hpp"
#include "AMateria.hpp"

class Ice : public AMateria, public Character {

    public:
        Ice();
        Ice(const std::string& _type);
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();

        AMateria* clone() const override;
};

#endif