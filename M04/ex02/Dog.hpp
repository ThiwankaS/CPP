#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	private:
		std::string name;
		Brain *brain;

	public:
		Dog();
		Dog(const std::string& _name);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound(void) const override;
		void brainSurgery(void) const;
		void giveIdea(const std::string& idea);
};

#endif
