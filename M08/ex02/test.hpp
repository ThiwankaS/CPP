#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#define HIGLIGHT_START	"\x1b[1m\x1b[38;2;0;0;0m\x1b[48;2;255;255;170m"
#define HIGLIGHT_END	"\x1b[0m"

#define TEST_NAME(test_name)\
    do {std::cout << " " << test_name << "\n"; } while (0)

#define LINE_DATA\
    do {std::cout << "---at--- : file [" << __FILE__ << "] line no : [" << __LINE__ << "]\n";} while (0)

#define NEW_LINE\
    do {std::cout << "\n";} while (0)

void test(const std::string& test_case);

#endif
