#include <iostream>
#include <string>

#include "test.hpp"
#include "Harl.hpp"

int main(void) {

	test("test case 01");
	TEST_NAME("Creating an instance of Harl classs");
	LINE_DATA;
	Harl log_system;
	std::cout << "Instantiation successfull! \n";
	LINE_DATA;

	test("test case 02");
	TEST_NAME("Calling complain with DEBUG");
	LINE_DATA;
	log_system.complain("DEBUG");
	LINE_DATA;

	test("test case 03");
	TEST_NAME("Calling complain with INFO");
	LINE_DATA;
	log_system.complain("INFO");
	LINE_DATA;

	test("test case 04");
	TEST_NAME("Calling complain with WARNING");
	LINE_DATA;
	log_system.complain("WARNING");
	LINE_DATA;

	test("test case 05");
	TEST_NAME("Calling complain with ERROR");
	LINE_DATA;
	log_system.complain("ERROR");
	LINE_DATA;

	test("test case 06");
	TEST_NAME("Calling complain with wrong level WRONG");
	LINE_DATA;
	log_system.complain("WRONG");
	LINE_DATA;

	return (EXIT_SUCCESS);
}
