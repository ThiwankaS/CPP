# include "validate.hpp"

/**
 * Pattern 01 will assure that a nme only includes alphabatical charcates
*/
# define PATTERN01 "^[a-zA-Z]+$"

/**
 * Pattern 02 will allow to use the E.164 formats
 * +358451234545 -> valid
 * +358 45 123 4545 -> valid
*/
# define PATTERN02 "^\\+(?:[0-9] ?){6,14}[0-9]$"

/**
 * Pattern 03 will allow to use local formats
 * (045) 123 4545
 * 045 123 4545
 * 045-123-4545
 * 0451234545
 * (045)-123-4545
*/
# define PATTERN03 "^\\(?([0-9]{3})\\)?[\\s-]?[0-9]{3}[\\s-]?[0-9]{4}$"

/**
 * validate a name, if name contains any character other than alphabatic
 * character function will return false, and return true otherwise
*/
bool isValidName(std::string name) {
    const std::regex pattern1 (PATTERN01);
    return (
        std::regex_match(name, pattern1)
    );
}

/**
 * validate a phone number to assure it follows either E.164 international standards
 * or pre-difine local formats
*/
bool isValidNumber(std::string number) {
    /**
     * creating respecting regex object for E.164 formats
    */
    const std::regex pattern2 (PATTERN02);
    /**
     * creating respective regex object for local formats
    */
    const std::regex pattern3 (PATTERN03);
    
    return (
            std::regex_match(number, pattern2)
        ||  std::regex_match(number, pattern3)
    );
}
