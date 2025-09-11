#include "Bureaucrat.hpp"

bool Bureaucrat::validateGrade(int g) const {
    if (g < 1)
        throw GradeTooHighException(GradeTooHighException::TooHigh);
    if (g > 150)
        throw GradeException(GradeException::TooLow);
    return (true);
}

Bureaucrat::Bureaucrat()
: name("default"), grade(150) {
    std::cout << "Bureaucrat default constructor.\n";
 }

Bureaucrat::Bureaucrat(const std::string& _name, int _grade)
: name(_name), grade(_grade) {
    validateGrade(grade);
    std::cout << "Bureaucrat argument constructor.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name(other.name), grade(other.grade) {
    validateGrade(grade);
    std::cout << "Bureaucrat copy constructor.\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if(this != &other) {
            grade = other.grade;
            /**
             * this will not work or even compile, but subject force us to implement
             * assigment operator, this assigment perator should not call under any
             * circumstance becaue it is not producing correct results
            */
            //name = other.name;
    }
    std::cout << "Bureaucrat assigment operator.\n";
    validateGrade(grade);
    return (*this);
}

Bureaucrat::~Bureaucrat() { 
    std::cout << "Bureaucrat destructor.\n";
}

int Bureaucrat::getGrade(void) const {
    return (grade);
}

std::string Bureaucrat::getName(void) const {
    return (name);
}

void Bureaucrat::incrementGrade(void) {
    grade -= 1;
    validateGrade(grade);
}

void Bureaucrat::decrementGrade(void) {
    grade += 1;
    validateGrade(grade);
}

void Bureaucrat::setGrade(int g) {
    this->grade = g;
    validateGrade(grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName()
       << ", bureaucrat grade "
       << b.getGrade();
    return (os);
}
