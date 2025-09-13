#include <iostream>

#include "AForm.hpp"
#include "test.hpp"
#include "Bureaucrat.hpp"
#include "GradeException.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void) {

    test("test case 01");
    TEST_NAME("Happy path - successfully signed and executed");
    LINE_DATA;
    try {
        Bureaucrat b1("Manager", 15), b2("Officer", 27);
        RobortomyRequestForm rb("Leave request");
        b2.signForm(rb);
        b1.executeForm(rb);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    test("test case 02");
    TEST_NAME("Trying to execute with out signing");
    LINE_DATA;
    try {
        Bureaucrat b1("Manager", 15), b2("Officer", 27);
        RobortomyRequestForm rb("Leave request");
        b1.executeForm(rb);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    test("test case 03");
    TEST_NAME("Trying to sign by lower grade bureaucrat");
    LINE_DATA;
    try {
        Bureaucrat b1("Manager", 15), b2("Officer", 75);
        RobortomyRequestForm rb("Leave request");
        b2.signForm(rb);
        b1.executeForm(rb);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    test("test case 04");
    TEST_NAME("Trying to execute by lower grade bureaucrat");
    LINE_DATA;
    try {
        Bureaucrat b1("Manager", 55), b2("Officer", 65);
        RobortomyRequestForm rb("Leave request");
        b2.signForm(rb);
        b1.executeForm(rb);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    test("test case 05");
    TEST_NAME("Happy path - successfully signed and executed | PresidentialPardonForm");
    LINE_DATA;
    try {
        Bureaucrat b1("Supirindent", 4), b2("Jailor", 15);
        PresidentialPardonForm pp("Pardon request");
        b2.signForm(pp);
        b1.executeForm(pp);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    test("test case 06");
    TEST_NAME("un-successful attempt | PresidentialPardonForm");
    LINE_DATA;
    try {
        Bureaucrat b1("Chef", 49), b2("Jailor", 15);
        PresidentialPardonForm pp("Pardon request");
        b2.signForm(pp);
        b1.executeForm(pp);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    test("test case 07");
    TEST_NAME("Happy path - successfully signed and executed | RobortomyRequestForm");
    LINE_DATA;
    try {
        Bureaucrat b1("Engineer", 30), b2("Technical Officer", 55);
        RobortomyRequestForm rb("Excavate request");
        b2.signForm(rb);
        b1.executeForm(rb);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    test("test case 08");
    TEST_NAME("un-successful attempt | RobortomyRequestForm");
    LINE_DATA;
    try {
        Bureaucrat b1("Engineer", 30), b2("Clarck", 75);
        RobortomyRequestForm rb("Excavate request");
        b2.signForm(rb);
        b1.executeForm(rb);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    test("test case 09");
    TEST_NAME("Happy path - successfully signed and executed | ShrubberyCreationForm");
    LINE_DATA;
    try {
        Bureaucrat b1("Manager", 130), b2("Conservation Officer", 140);
        ShrubberyCreationForm sc("Jungle");
        b2.signForm(sc);
        b1.executeForm(sc);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    test("test case 10");
    TEST_NAME("un-successful attempt | ShrubberyCreationForm");
    LINE_DATA;
    try {
        Bureaucrat b1("Lumber Jack", 150), b2("Conservation Officer", 140);
        ShrubberyCreationForm sc("Jungle");
        b2.signForm(sc);
        b1.executeForm(sc);
    } catch (const GradeException& e) {
        std::cerr <<"Error : "
				  << e.what()
				  << std::endl;
    }

    return (EXIT_SUCCESS);
}
