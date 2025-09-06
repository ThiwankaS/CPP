#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

    private:
        std::string name;
        Brain *brain;

    public:
        Cat();
        Cat(const std::string& _name);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();

        void makeSound(void) const override;
};

#endif


