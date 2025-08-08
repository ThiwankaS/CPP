# ifndef UTILITIES_HPP
#  define UTILITIES_HPP

# include <iostream>
# include <string>
# include <regex>
# include <iomanip>

// constant to detemine the column width in printColumn
constexpr int width = 10;

// data validation functions
bool isValidName(std::string name);
bool isValidNumber(std::string number);
bool isNotBlank(std::string text);
bool isValidIndex(std::string index);

// displaying a string based on predefined format
void printColumn(const std::string text);

# endif
