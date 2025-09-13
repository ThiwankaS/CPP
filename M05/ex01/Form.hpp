#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "CustomeException.hpp"

class Bureaucrat;
class Form {

    private:
        const std::string name;
        bool is_signed;
        int grade_required_sign;
        int grade_required_execute;

    public:
        //constructors & destructor
        Form();
        Form(const std::string& _name, int sign_grade, int execute_grade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        //exception handling
        struct GradeTooHighException : public CustomeException {
            private:
                std::string msg;

            public:
                explicit GradeTooHighException(const std::string& str)
                : msg(str) {}
                const char* what() const noexcept override {
                    return (msg.c_str());
                }
        };

        struct GradeTooLowException : public CustomeException {
            private:
                std::string msg;

            public:
                explicit GradeTooLowException(const std::string& str)
                : msg(str) {}
                const char* what() const noexcept override {
                    return (msg.c_str());
                }
        };

        //class methods
        bool validateGrade(int grade) const;
        bool validateExecution(int grade) const;
        bool validateSigning(int grade) const;
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeRequiredToSign(void) const;
        int getGradeRequiredToExecute(void) const;
        void setIsSigned(bool status);
        void setGradeRequiredToSign(int grade);
        void setGradeRequiredToExecute(int grade);
        void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
