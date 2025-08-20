#include <iostream>
#include <string>

#include "test.hpp"
#include "Fixed.hpp"

int main (void) {

    test("test case 01");
    TEST_NAME("Instantiation of \'a\' from class \'Fixed\'");
    LINE_DATA;
    Fixed a;
    LINE_DATA;

    test("test case 02");
    TEST_NAME("Instantiation of \'b\' from copying properties object \'a\'");
    LINE_DATA;
    Fixed b(a);
    LINE_DATA;

    test("test case 02");
    TEST_NAME("Instantiation of \'c\' from assigning properties from object \'b\'");
    LINE_DATA;
    Fixed c;
    c = b;
    LINE_DATA;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return (EXIT_SUCCESS);
}
