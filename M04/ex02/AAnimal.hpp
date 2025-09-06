#ifndef  AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>


class AAnimal {

	protected:
		std::string type;

	public:
		//constructors and destructors
		AAnimal();
		AAnimal(const std::string& _type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		//class methods
		virtual void makeSound(void) const = 0;
};

#endif
