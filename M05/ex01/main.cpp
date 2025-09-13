#include <iostream>

#include "Form.hpp"
#include "test.hpp"
#include "Bureaucrat.hpp"
#include "CustomeException.hpp"

int main (void) {

	{
		test("test case 01");
		TEST_NAME("instantiate Form with default values");
		LINE_DATA;
		try {
				Form f;
				LINE_DATA;
				std::cout << f << std::endl;
				LINE_DATA;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 02");
		TEST_NAME("instantiate Form with valid values");
		LINE_DATA;
		try {
				Form f("Funding application", 5, 1);
				LINE_DATA;
				std::cout << f << std::endl;
				LINE_DATA;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 03");
		TEST_NAME("instantiate Form with invalid values");
		LINE_DATA;
		try {
				Form f("Entrance application", 10, 20);
				LINE_DATA;
				std::cout << f << std::endl;
				LINE_DATA;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 04");
		TEST_NAME("instantiate Form with invalid values");
		LINE_DATA;
		try {
				Form f("Refunding application", 4, 0);
				LINE_DATA;
				std::cout << f << std::endl;
				LINE_DATA;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 05");
		TEST_NAME("instantiate Form with invalid values");
		LINE_DATA;
		try {
				Form f("Some other application", 151, 18);
				std::cout << f << std::endl;
				LINE_DATA;
				std::cout << f << std::endl;
				LINE_DATA;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
		{
		test("test case 06");
		TEST_NAME("form signed by bureaucrat valid signing");
		LINE_DATA;
		try {
				LINE_DATA;
				Bureaucrat b("CEO", 1);
				std::cout << b << std::endl;
				LINE_DATA;
				Form f("IPO initiation", 5, 3);
				std::cout << f << std::endl;
				LINE_DATA;
				b.signForm(f);
				LINE_DATA;
				std::cout << f << std::endl;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 07");
		TEST_NAME("form signed by bureaucrat invalid signing");
		LINE_DATA;
		try {
				LINE_DATA;
				Bureaucrat b("HR Manager", 25);
				std::cout << b << std::endl;
				LINE_DATA;
				Form f("IPO initiation", 5, 1);
				std::cout << f << std::endl;
				LINE_DATA;
				b.signForm(f);
				LINE_DATA;
				std::cout << f << std::endl;
		} catch(const CustomeException& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
    return (EXIT_SUCCESS);
}
