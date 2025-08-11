# include "utilities.hpp"

/**
 * @brief Pattern 01, a name only includes alphabatical charcates
*/
# define PATTERN01 "^[a-zA-Z]+$"

/**
 * @brief Pattern 02 will allow to use the E.164 formats
 * +358451234545 -> valid
 * +358 45 123 4545 -> valid
*/
# define PATTERN02 "^\\+(?:[0-9] ?){6,14}[0-9]$"

/**
 * @brief Pattern 03 will allow to use local formats
 * (045) 123 4545
 * 045 123 4545
 * 045-123-4545
 * 0451234545
 * (045)-123-4545
*/
# define PATTERN03 "^\\(?([0-9]{3})\\)?[\\s-]?[0-9]{3}[\\s-]?[0-9]{4}$"

/**
 * @brief Pattern 04 will assure the string is not filled with isspace() characters
*/
# define PATTERN04 ".*\\S.*"

/**
 * @brief only accept digits, 0 - 9
*/
# define PATTERN05 "^[0-9]+$"

/**
 * @brief validate a name, if name contains any character other than alphabatic
 * character function will return false, and return true otherwise
 * @param name name to be validated
 * @return true if valid
*/
bool isValidName(std::string name) {
    const std::regex pattern1 (PATTERN01);
    return (
        std::regex_match(name, pattern1)
    );
}

/**
 * @brief validate a phone number to assure it follows either E.164 international
 * standards or pre-difine local formats
 * @param number to be validated
 * @return true if valid
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

/**
 * @brief validate the input not contain any empty data
 * @param text string need to be validated
 * @return true if valid
*/
bool isNotBlank(std::string text) {

    const std::regex pattern4 (PATTERN04);

    return (
            std::regex_match(text, pattern4)
    );
}

/**
 * @brief checking the index user entered is in the range
 * @param index index need to be validated
 * @return true if vaild
*/
bool isValidIndex(std::string index) {
    const std::regex pattern5 (PATTERN05);

    return (
            std::regex_match(index, pattern5)
    );
}

/**
 * @brief displaying a text|string base on a predefined format
 * column width will be 10 (width)
 * pipe character (’|’) separates
 * right-aligned
 * If the text is longer than the column,   it must be truncated
 * and the last displayable character must be replaced by a dot (’.’).
 * @param text string need be formated
*/
void printColumn(const std::string text) {
    if (text.length() < width) {
        std::cout << std::right << std::setw(width) << text << "|";
    } else {
        std::cout << std::right << std::setw(width - 1) << text.substr(0, width - 1) << "." << "|";
    }

}
