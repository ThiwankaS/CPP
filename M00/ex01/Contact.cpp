# include "Contact.hpp"

/**
 * no data provided during the object creation hence assigning the default values
*/
Contact::Contact(void) {
    first_name_     = "N/A";
    last_name_      = "N/A";
    nick_name_      = "N/A";
    phone_number_   = "xxx-xxx xxx xxx";
    darkest_secret_ = "N/A";
}

/**
 * only mandotory data is provided and rest of the varibales will be assigned
 * the default values
*/
Contact :: Contact (std::string f_name,std::string p_number) {
    first_name_     = f_name;
    last_name_      = "N/A";
    nick_name_      = "N/A";
    phone_number_   = p_number;
    darkest_secret_ = "N/A";
}

/**
 * all the required data is provided and all the varibales will be assigned
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
