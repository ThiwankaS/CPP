#include <iostream>

#include "Form.hpp"
#include "test.hpp"

int main (void) {

	{
		test("test case 01");
		TEST_NAME("Creating a Form with default values");
		LINE_DATA;
		try {
				Form f;
				std::cout << f << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 02");
		TEST_NAME("Creating a Form with a name and a valid grade");
		LINE_DATA;
		try {
				Form f("Funding application", 5, 1);
				std::cout << f << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 03");
		TEST_NAME("Creating a Form with a name and a valid grade");
		LINE_DATA;
		try {
				Form f("Entrance application", 148, 20);
				std::cout << f << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 04");
		TEST_NAME("Creating a Form with a name and a invalid grade");
		LINE_DATA;
		try {
				Form f("Refunding application", 4, 0);
				std::cout << f << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
	{
		test("test case 05");
		TEST_NAME("Creating a Form with a name and a invalid grade");
		LINE_DATA;
		try {
				Form f("Some other application", 151, 149);
				std::cout << f << std::endl;
				LINE_DATA;
				std::cout << f << std::endl;
		} catch(const std::exception& e){
			std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
	    }
	}
    return (EXIT_SUCCESS);
}
