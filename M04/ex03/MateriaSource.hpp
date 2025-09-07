#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define SIZE 4

class MateriaSource : public IMateriaSource {

    private:
        AMateria* accquired[SIZE];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        ~MateriaSource();

        void learnMateria(AMateria* m) override;
        AMateria* createMateria(std::string const & type) override;
};
#endif
