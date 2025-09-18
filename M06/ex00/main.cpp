#include <iostream>
#include <string>
#include <exception>

#include "ScalarConverter.hpp"

int main (int argc, char* argv[]) {

	if(argc == 2) {
		ScalarConverter::convert(argv[1]);
	}
    return (EXIT_SUCCESS);
}
