#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for(int i = 0; i < SIZE; i ++) {
        accquired[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for(int i = 0; i < SIZE; i ++) {
        if(other.accquired[i])
            accquired[i] = other.accquired[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if(this != &other) {
        for(int i = 0; i < SIZE; i++) {
            if(other.accquired[i])
                accquired[i] = other.accquired[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource() {
    for(int i = 0; i < SIZE; i++) {
            if(accquired[i])
                delete accquired[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for(int i = 0; i < SIZE; i++) {
        if(accquired[i] == NULL){
            accquired[i] = m->clone();
            delete m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for(int i = 0; i < SIZE; i++) {
        if (accquired[i] && accquired[i]->getType() == type) {
            return (accquired[i]->clone());
        }
    }
    return (0);
}
