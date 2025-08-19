#include <iostream>
#include <string>


#include "Harl.hpp"

int main(int argc, char *argv[]) {

	Harl log_system;

	if(argc != 2) {
		std::cerr << "Incorrect no of arguments! \n";
		return (EXIT_FAILURE);
	}
	log_system.complain(argv[1]);

	return (EXIT_SUCCESS);
}
