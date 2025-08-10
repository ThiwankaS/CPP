# ifndef CONTACT_HPP
#  define CONTACT_HPP

# include <iostream>
# include <string>

# include "utilities.hpp"

class Contact {

    private :
        std::string first_name_;
        std::string last_name_;
        std::string nick_name_;
        std::string phone_number_;
        std::string darkest_secret_;

    public  :
        //constructors
        Contact();
        Contact(
            std::string f_name,
            std::string l_name,
            std::string n_name,
            std::string p_number,
            std::string secret
        );
        //default destructor
        ~Contact() = default;

        //class methods
        void print(void);
        void view(void);
};

# endif
