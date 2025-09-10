#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: name("default"), grade(150) {
    std::cout << "Bureaucrat default constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, const int _grade)
: name(_name), grade(_grade) {
    std::cout << "Bureaucrat argument constructor is called" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name(other.name), grade(other.grade) {
    std::cout << "Bureaucrat copy constructor is called" << std::endl;
}

// Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
//     if(this != &other) {
//         name(other.name);
//         grade = other.this;
//     }
//     std::cout << "Bureaucrat assigment constructor is called" << std::endl;
//     return (*this); 
// }

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor is called" << std::endl;
}