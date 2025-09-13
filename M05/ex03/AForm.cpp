#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm()
: name("default"), is_signed(false), grade_required_sign(150), grade_required_execute(149) {
    validateGrade(grade_required_sign);
    validateGrade(grade_required_execute);
    validateGradeLevel();
}

AForm::AForm(const std::string& _name, int sign_grade, int execute_grade)
: name(_name), is_signed(false), grade_required_sign(sign_grade), grade_required_execute(execute_grade) {
    validateGrade(grade_required_sign);
    validateGrade(grade_required_execute);
    validateGradeLevel();
}

AForm::AForm(const AForm& other)
: name(other.name), is_signed(other.is_signed), grade_required_sign(other.grade_required_sign), grade_required_execute(other.grade_required_execute) {
    validateGrade(grade_required_sign);
    validateGrade(grade_required_execute);
    validateGradeLevel();
}

AForm& AForm::operator=(const AForm& other) {
    if(this != &other) {
        is_signed = other.is_signed;
        grade_required_sign = other.grade_required_sign;
        grade_required_execute = other.grade_required_execute;
        /**
             * this will not work or even compile, but subject force us to implement
             * assigment operator, this assigment perator should not call under any
             * circumstance becaue it is not producing correct results
        */
        //name = other.name;
    }
    validateGrade(grade_required_sign);
    validateGrade(grade_required_execute);
    validateGradeLevel();
    return (*this);
}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName()
       << " ,signed status : "
       << (f.getIsSigned() ? "true" : "false")
       << " ,grade required to sign : "
       << f.getGradeRequiredToSign()
       << " ,grade required to execute : "
       << f.getGradeRequiredToExecute()
       << std::endl;
       return (os);
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
bool AForm::validateGrade(int g) const {
    if (g < 1)
        throw GradeTooHighException("Grade too high : Maximum value possible 01");
    if (g > 150)
        throw GradeTooLowException("Grade too low : Minimum value possible 150");
    return (true);
}

bool AForm::validateGradeLevel(void) const {
    if(grade_required_execute >= grade_required_sign)
        throw ("Grade to execute must be lager than grade to sign");
    return (true);
}

bool AForm::validateExecution(int grade) const {
    if (grade >= grade_required_execute)
        throw GradeTooLowException("Grade must be lager than grade to execute");
    return (true);
}

bool AForm::validateSigning(int grade) const {
    if(grade >= grade_required_sign)
        throw GradeTooLowException("Grade must be larger than grade to sign");
    return (true);
}

std::string AForm::getName(void) const {
    return (name);
}

bool AForm::getIsSigned(void) const {
    return (is_signed);
}

int AForm::getGradeRequiredToSign(void) const {
    return (grade_required_sign);
}

int AForm::getGradeRequiredToExecute(void) const {
    return (grade_required_execute);
}

void AForm::setIsSigned(bool status) {
    is_signed = status;
}

void AForm::setGradeRequiredToSign(int grade) {
    grade_required_sign = grade;
    validateGrade(grade_required_sign);
}

void AForm::setGradeRequiredToExecute(int grade) {
    grade_required_execute = grade;
    validateGrade(grade_required_execute);
}

void AForm::beSigned(const Bureaucrat& b) {
    if(validateSigning(b.getGrade()))
        setIsSigned(true);
}

void AForm::execute(const Bureaucrat& executor) const {
    if(getIsSigned()) {
        if(validateExecution(executor.getGrade()))
            this->action();
    } else {
        throw FormNotSigned("the form need to sign before excute");
    }
}

