#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "GradeException.hpp"

class Form {

    public:
        //constructors & destructor
        Form();
        Form(const std::string& _name, int sign_grade, int execute_grade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        //exception handling
        class GradeTooHighException : virtual public GradeException {
            public:
                explicit GradeTooHighException(Type _type) : GradeException(_type) {}
        };

        class GradeTooLowException : virtual public GradeException {
            public:
                explicit GradeTooLowException(Type _type) : GradeException(_type) {}
        };

        //class methods
        bool validateGrade(int grade) const;
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeRequiredToSign(void) const;
        int getGradeRequiredToExecute(void) const;
        void setIsSigned(bool status);
        void setGradeRequiredToSign(int grade);
        void setGradeRequiredToExecute(int grade);

    private:
        const std::string name;
        bool is_signed;
        int grade_required_sign;
        int grade_required_execute;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif