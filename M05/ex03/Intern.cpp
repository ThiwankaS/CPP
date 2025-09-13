#include <iostream>
#include <cstddef>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static AForm* makeShrubbery(const std::string& t) {
    return (
        new ShrubberyCreationForm(t)
    );
}

static AForm* makeRobot(const std::string& t) {
    return (
        new RobortomyRequestForm(t)
    );
}

static AForm* makePresident(const std::string& t) {
    return (
        new PresidentialPardonForm(t)
    );
}

typedef AForm* (*factory_t)(const std::string&);

struct Entry {
    const char* name;
    factory_t create;
};

static Entry const entries [] = {
    {"shrubbery creation", &makeShrubbery},
    {"robotomy request", &makeRobot},
    {"presidential pardon", &makePresident}
};

AForm* Intern::makeForm(const std::string& form_name, const std::string& target) const throw() {
    try {
        for(int i = 0; i < 3;i++) {
            if(entries[i].name == form_name) {
                std::cout << "Intern creates "
                      << form_name
                      << std::endl;
                return (entries[i].create(target));
            }
        }
        throw(NotFoundClassExecption());
    } catch (const CustomeException& e) {
        std::cerr << "Intern can not create "
                  << form_name
                  << " because "
                  << e.what()
                  << std::endl;
        return (nullptr);
    }
}
