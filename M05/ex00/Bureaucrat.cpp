#include "Bureaucrat.hpp"

bool Bureaucrat::validateGrade(int g) const {
    if (g < 1)
        throw GradeException(GradeException::TooLow);
    if (g > 150)
        throw GradeException(GradeException::TooHigh);
    return (true);
}

Bureaucrat::Bureaucrat()
: name("default"), grade(150) {
    std::cout << "Bureaucrat default constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade)
: name(_name), grade(_grade) {
    validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name(other.name), grade(other.grade) {
    validateGrade(grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if(this != &other) {
        grade = other.grade;
        validateGrade(grade);
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() { }

const char* Bureaucrat::GradeException::what() const noexcept {
    return (
        type == TooHigh
            ? "Grade too high"
            : "Grade too low"
    );
}

int Bureaucrat::getGrade(void) const {
    return (grade);
}

std::string Bureaucrat::getName(void) const {
    return (name);
}

void Bureaucrat::incrementGrade(void) {
    grade += 1;
    validateGrade(grade);
}

void Bureaucrat::decrementGrade(void) {
    grade -= 1;
    validateGrade(grade);
}
