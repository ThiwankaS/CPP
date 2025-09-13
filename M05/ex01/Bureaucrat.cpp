#include "Bureaucrat.hpp"
#include "Form.hpp"

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

/**
 * @brief Validates the Bureaucrat's grade value.
 * Ensures that the given grade `g` is within the allowed range [1, 150].
 * - If `g < 1`, a `GradeTooHighException` is thrown.
 * - If `g > 150`, a `GradeTooLowException` is thrown.
 * - Otherwise, the grade is valid and the function returns `true`.
 * @param g The grade value to validate.
 * @return `true` if the grade is valid.
 * @throws GradeTooHighException If the grade is less than 1.
 * @throws GradeTooLowException If the grade is greater than 150.
 */
bool Bureaucrat::validateGrade(int g) const {
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();
    return (true);
}

/**
 * @brief Increments the Bureaucrat's grade by 1.
 * This function decreases the internal `grade` value by 1
 * (since lower numbers represent higher grades)
 * and then validates the updated grade using `validateGrade()`.
 * @note Throws an exception if the resulting grade is out of bounds.
 * @see Bureaucrat::validateGrade
*/
void Bureaucrat::incrementGrade(void) {
    grade -= 1;
    validateGrade(grade);
}

/**
 * @brief Decrements the Bureaucrat's grade by 1.
 * This function increases the internal `grade` value by 1
 * (since higher numbers represent lower grades)
 * and then validates the updated grade using `validateGrade()`.
 * @note Throws an exception if the resulting grade is out of bounds.
 * @see Bureaucrat::validateGrade
 */
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

void Bureaucrat::signForm(Form& f) const {
    try {
            f.beSigned(*this);
            std::cout << this->getName()
                    << "  signed "
                    << f.getName()
                    << " form.\n";
    } catch(const CustomeException& e) {
            std::cerr << this->getName()
                    << " couldn\'t signed "
                    << f.getName()
                    << " form because "
                    << e.what()
                    << "\n";
    }
}
