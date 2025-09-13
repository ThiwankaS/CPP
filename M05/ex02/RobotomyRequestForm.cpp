#include "RobotomyRequestForm.hpp"

RobortomyRequestForm::RobortomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobortomyRequestForm::RobortomyRequestForm(const std::string& _target)
: AForm("RobotomyRequestForm", 72, 45), target(_target) {}

RobortomyRequestForm::RobortomyRequestForm(const RobortomyRequestForm& other)
: AForm("RobotomyRequestForm", 72, 45), target(other.target) {}

RobortomyRequestForm& RobortomyRequestForm::operator=(const RobortomyRequestForm& other) {
    if(this != &other) {
        *this = other;
    }
    return (*this);
}

RobortomyRequestForm::~RobortomyRequestForm() {}

void RobortomyRequestForm::action(void) const {
    std::cout << "Makes some drilling noise..." << std::endl;
    std::cout << target
              << " has been robotomized successfully 50\% of the time."
              << std::endl;
}
