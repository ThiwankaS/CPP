#include <iostream>

#include "Bureaucrat.hpp"
#include "test.hpp"
#include "CustomeException.hpp"

int main (void) {

	{
		test("test case 01");
		TEST_NAME("instantiate Bureacrat with default values");
		LINE_DATA;
		try {
				Bureaucrat b;
				std::cout << b << std::endl;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 02");
		TEST_NAME("instantiate Bureaucrat with valid values");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 1);
				std::cout << b << std::endl;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 03");
		TEST_NAME("increase grade of a Bureaucrat instance to a valid value");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 149);
				std::cout << b << std::endl;
				LINE_DATA;
				b.incrementGrade();
				std::cout << b << std::endl;
				LINE_DATA;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 04");
		TEST_NAME("Decrease grade of a bureaucrat to invalid grade");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 1);
				std::cout << b << std::endl;
				LINE_DATA;
				b.decrementGrade();
				std::cout << b << std::endl;
				LINE_DATA;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 05");
		TEST_NAME("increase grade of a Bureaucrat instance to a invalid value");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 1);
				std::cout << b << std::endl;
				LINE_DATA;
				b.incrementGrade();
				std::cout << b << std::endl;
				LINE_DATA;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 06");
		TEST_NAME("decrease grade of a Bureaucrat instance to a invalid grade");
		LINE_DATA;
		try {
				Bureaucrat b("Eddie", 150);
				std::cout << b << std::endl;
				LINE_DATA;
				b.decrementGrade();
				std::cout << b << std::endl;
				LINE_DATA;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
    return (EXIT_SUCCESS);
}
