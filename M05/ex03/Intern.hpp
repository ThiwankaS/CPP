#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "CustomeException.hpp"

class AForm;

class Intern {

    public:
        struct NotFoundClassExecption : public CustomeException {
            const char* what() const noexcept override {
                return ("could not found specified class implemention");
            }
        };
        AForm* makeForm(const std::string& form_name, const std::string& target) const throw();
};

#endif
