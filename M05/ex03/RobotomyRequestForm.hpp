#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobortomyRequestForm : public AForm {
    private:
        std::string target;

    public:
        RobortomyRequestForm();
        RobortomyRequestForm(const std::string& _target);
        RobortomyRequestForm(const RobortomyRequestForm& other);
        RobortomyRequestForm& operator=(const RobortomyRequestForm& other);
        ~RobortomyRequestForm();

        void action(void) const override;
};

#endif
