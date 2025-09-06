#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	private:
		std::string name;
		Brain *brain;

	public:
		Dog();
		Dog(const std::string& _name);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound(void) const;
		void brainSurgery(void) const;
		void giveIdea(const std::string& idea);
};

#endif
