#ifndef  WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>


class WrongAnimal {

	protected:
		std::string type;

	public:
		//constructors and destructors
		WrongAnimal();
		WrongAnimal(const std::string& _type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();

		//class methods
		void makeSound(void) const;
};

#endif
