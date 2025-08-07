# ifndef UTILITIES_HPP
#  define UTILITIES_HPP

# include <iostream>
# include <string>
# include <regex>
# include <iomanip>

constexpr int width = 10;

bool isValidName(std::string name);
bool isValidNumber(std::string number);
bool isNotBlank(std::string text);

void printColumn(const std::string text);

# endif
