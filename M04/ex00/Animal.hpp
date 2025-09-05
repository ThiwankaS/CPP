#ifndef  ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>


class Animal {

	protected:
		std::string type;

	public:
		//constructors and destructors
		Animal();
		Animal(const std::string& _type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		~Animal();

		//class methods
		virtual void makeSound(void) const;
};

#endif
