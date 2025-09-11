#include <iostream>

#include "Bureaucrat.hpp"
#include "test.hpp"

int main (void) {

	{
		test("test case 01");
		TEST_NAME("Creating a Bureacrat with default values");
		LINE_DATA;
		try {
				Bureaucrat b;
				std::cout << b << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 02");
		TEST_NAME("Creating a Bureacrat with a name and a valid grade");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 1);
				std::cout << b << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 03");
		TEST_NAME("Increase the grade of a bureaucrat to valid grade");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 149);
				std::cout << b << std::endl;
				LINE_DATA;
				b.incrementGrade();
				std::cout << b << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 04");
		TEST_NAME("Increase the grade of a bureaucrat to invalid grade");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 150);
				std::cout << b << std::endl;
				LINE_DATA;
				b.incrementGrade();
				std::cout << b << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 05");
		TEST_NAME("Decrease the grade of a bureaucrat to valid grade");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 2);
				std::cout << b << std::endl;
				LINE_DATA;
				b.decrementGrade();
				std::cout << b << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 05");
		TEST_NAME("Decrease the grade of a bureaucrat to invalid grade");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 1);
				std::cout << b << std::endl;
				LINE_DATA;
				b.decrementGrade();
				std::cout << b << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
    return (EXIT_SUCCESS);
}
