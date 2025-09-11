#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "GradeException.hpp"

class Bureaucrat {

    public:
        //constructors & destructor
        Bureaucrat();
        Bureaucrat(const std::string& _name, int _grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        //class methods
        bool validateGrade(int grade) const;
        int getGrade(void) const;
        std::string getName(void) const;
        void setGrade(int g);
        void incrementGrade(void);
        void decrementGrade(void);

        //exception handling
        class GradeTooHighException : virtual public GradeException {
            public:
                explicit GradeTooHighException(Type _type) : GradeException(_type) {}
        };

        class GradeTooLowException : virtual public GradeException {
            public:
                explicit GradeTooLowException(Type _type) : GradeException(_type) {}
        };
    
    private:
        const std::string name;
        int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
