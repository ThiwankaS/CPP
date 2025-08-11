# include "Contact.hpp"

/**
 * @brief no data provided during the object creation hence assigning
 * the default values
*/
Contact::Contact(void) {
    first_name_     = "xxxxxxxxxx";
    last_name_      = "xxxxxxxxxx";
    nick_name_      = "**********";
    phone_number_   = "xxx-xxx xxx xxx";
    darkest_secret_ = "**********";
}

/**
 * @brief  all the required data is provided and all the varibales will be assigned
 * the corresponding values
*/
Contact :: Contact (
            std::string f_name,
            std::string l_name,
            std::string n_name,
            std::string p_number,
            std::string secret
        ) {
    first_name_     = f_name;
    last_name_      = l_name;
    nick_name_      = n_name;
    phone_number_   = p_number;
    darkest_secret_ = secret;
}

/**
 * @brief  displaying all the filed in a contact record follwing the formatting
 * guidelines
*/
void Contact::print(void) {
    printColumn(this->first_name_);
    printColumn(this->last_name_);
    printColumn(this->nick_name_);
}

/**
 * @brief  displaying  all the filed in a contact record one filed in line
*/
void Contact::view(void) {
    std::cout << "\n";
    std::cout << " First Name       : " << this->first_name_ << std::endl;
    std::cout << " Last Name        : " << this->last_name_ << std::endl;
    std::cout << " Nick Name        : " << this->nick_name_ << std::endl;
    std::cout << " Phone Number     : " << this->phone_number_ << std::endl;
    std::cout << " Dark Secret      : " << this->darkest_secret_ << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}
