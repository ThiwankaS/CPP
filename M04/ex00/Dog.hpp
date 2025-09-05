#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Dog : public Animal {

	private:
		std::string name;

	public:
		Dog();
		Dog(const std::string& _name);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound(void) const;
};

#endif
