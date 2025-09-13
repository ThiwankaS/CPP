#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target)
: AForm("PresidentialPardonForm", 25, 5), target(_target)  {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm("PresidentialPardonForm", 25, 5), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if(this != &other) {
        *this = other;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action(void) const {
    std::cout << target
              << " has been pardon by Zaphod Beeblebrox."
              << std::endl;
}
