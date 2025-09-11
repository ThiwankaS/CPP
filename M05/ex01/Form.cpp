#include "Form.hpp"

bool Form::validateGrade(int g) const {
    if (g < 1)
        throw GradeTooHighException(GradeTooHighException::TooHigh);
    if (g > 150)
        throw GradeException(GradeException::TooLow);
    return (true);
}

Form::Form() 
: name("default"), is_signed(false), grade_required_sign(150), grade_required_execute(149) {
    validateGrade(grade_required_sign);
    validateGrade(grade_required_execute);
}

Form::Form(const std::string& _name, int sign_grade, int execute_grade)
: name(_name), is_signed(false), grade_required_sign(sign_grade), grade_required_execute(execute_grade) {
    validateGrade(grade_required_sign);
    validateGrade(grade_required_execute);
}

Form::Form(const Form& other)
: name(other.name), is_signed(other.is_signed), grade_required_sign(other.grade_required_sign), grade_required_execute(other.grade_required_execute) {
    validateGrade(grade_required_sign);
    validateGrade(grade_required_execute);
}

Form& Form::operator=(const Form& other) {
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
    return (*this);
}

Form::~Form() {}

std::ostream& operator<<(std::ostream& os, const Form& f) {
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

std::string Form::getName(void) const {
    return (name);
}

bool Form::getIsSigned(void) const {
    return (is_signed);
}

int Form::getGradeRequiredToSign(void) const {
    return (grade_required_sign);
}

int Form::getGradeRequiredToExecute(void) const {
    return (grade_required_execute);
}

void Form::setIsSigned(bool status) {
    is_signed = status;
}

void Form::setGradeRequiredToSign(int grade) {
    grade_required_sign = grade;
    validateGrade(grade_required_sign);
}

void Form::setGradeRequiredToExecute(int grade) {
    grade_required_execute = grade;
    validateGrade(grade_required_execute);
}

