#include <iostream>
#include <string>
#include <exception>

#include "ScalarConverter.hpp"

int main (int argc, char* argv[]) {

	if(argc == 2) {
		ScalarConverter::convert(argv[1]);
	} else {
		std::cout << "Invalid argument(s) : use the fromat ./convert <number_literal> " << std::endl;
	}
    return (EXIT_SUCCESS);
}
