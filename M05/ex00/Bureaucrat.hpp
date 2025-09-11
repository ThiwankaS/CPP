#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {

    private:
        const std::string name;
        int grade;
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
        class GradeException : public std::exception {

            public:
                enum Type { TooHigh, TooLow };
                explicit GradeException (Type _type) throw()
                    : type(_type) {}
                virtual const char *what() const throw() override;

            private:
                Type type;
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
