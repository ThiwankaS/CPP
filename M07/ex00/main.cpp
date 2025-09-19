#include <iostream>
#include <exception>
#include <string>

#include "whatever.hpp"

int main (void) {

	try {
			int a = 2;
			int b = 3;
			::swap( a, b );
			std::cout << "a = " << a << ", b = " << b << std::endl;
			std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
			std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	try {
			std::string c = "chaine1";
			std::string d = "chaine2";
			::swap(c, d);
			std::cout << "c = " << c << ", d = " << d << std::endl;
			std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
			std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
    return (EXIT_SUCCESS);
}
