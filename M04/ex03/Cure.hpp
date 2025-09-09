#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Cure : public AMateria {

    public:
        Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        ~Cure();

        AMateria* clone() const override;
        void use(ICharacter& target) override;
};

#endif
