#include <iostream>

#include "Intern.hpp"
#include "AForm.hpp"
#include "test.hpp"
#include "Bureaucrat.hpp"
#include "CustomeException.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void) {

    test("test case 01");
    TEST_NAME("Creating a form with non existing class name");
    LINE_DATA;
    try {
        Intern intern;
        AForm *f1 = intern.makeForm("SomeRandomForm", "Nowehere");
        if(f1 != nullptr) {
            std::cout << *f1 << std::endl;
            delete f1;
        }
    }
    catch (const CustomeException& e) {
        std::cerr << e.what() << std::endl;
    }

    test("test case 02");
    TEST_NAME("Creating a form with valid data");
    LINE_DATA;
    try {
        Intern intern;
        AForm *f1 = intern.makeForm("RobotomyRequestForm", "Factory");
        Bureaucrat b1("Engineer", 15), b2("Technician", 27);
        if(f1 != nullptr) {
            std::cout << *f1 << std::endl;
            b2.signForm(*f1);
            b1.executeForm(*f1);
            delete f1;
        }
    } catch (const CustomeException& e) {
        std::cerr << e.what() << std::endl;
    }
    return (EXIT_SUCCESS);
}
