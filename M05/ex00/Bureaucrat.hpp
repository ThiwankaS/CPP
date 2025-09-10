#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {

    private:
        const std::string name;
        const int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& _name, const int _grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other) = delete;
        ~Bureaucrat();
        void print(void) {
            std::cout << "name : " << name << " | grade : " << grade << std::endl; 
        }
};

#endif