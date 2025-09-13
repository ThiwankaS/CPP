#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "CustomeException.hpp"

class Bureaucrat;
class AForm {

    private:
        const std::string name;
        bool is_signed;
        int grade_required_sign;
        int grade_required_execute;

    public:
        //constructors & destructor
        AForm();
        AForm(const std::string& _name, int sign_grade, int execute_grade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

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

        struct FormNotSigned : public CustomeException {
            private:
                std::string msg;

            public:
                explicit FormNotSigned (const std::string& str)
                : msg(str) {}
                const char* what() const noexcept override {
                    return (msg.c_str());
                }
        };

        //class methods
        bool validateGrade(int grade) const;
        bool validateExecution(int grade) const;
        bool validateSigning(int grade) const;
        bool validateGradeLevel(void) const;
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeRequiredToSign(void) const;
        int getGradeRequiredToExecute(void) const;
        void setIsSigned(bool status);
        void setGradeRequiredToSign(int grade);
        void setGradeRequiredToExecute(int grade);
        void beSigned(const Bureaucrat& b);
        void execute(const Bureaucrat& executor) const;
        virtual void action(void) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
