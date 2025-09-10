#include <iostream>

#include "Bureaucrat.hpp"
#include "test.hpp"

int main (void) {

	try
	{
		Bureaucrat b("Thiwanka", 1);
		b.print();
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	}
    return (EXIT_SUCCESS);
}
