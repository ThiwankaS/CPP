#include <iostream>

#include "test.hpp"
#include "bsp.hpp"


int main (void) {

    test("test case 01");
    TEST_NAME("Creating a trangale");
    Point a(4.0f, 6.0f), b(8.0f, 4.0f), c(-2.0f, -2.0f);
    std::cout << "a : "; std::cout << a; std::cout << "\n";
    std::cout << "b : "; std::cout << b; std::cout << "\n";
    std::cout << "c : "; std::cout << c; std::cout << "\n";

    test("test case 02");
    TEST_NAME("Creating a point P0 inside the trangale and test");
    Point p0(3.0f, 3.0f);
    check_point(a, b, c, p0);

    test("test case 03");
    TEST_NAME("Creating a point P1 outside the trangale and test");
    Point p1(6.0f, 5.0f);
    check_point(a, b, c, p1);

    test("test case 04");
    TEST_NAME("Creating a point P2 outside the trangale and test");
    Point p2(3.0f, 1.0f);
    check_point(a, b, c, p2);

    test("test case 05");
    TEST_NAME("Creating a point P3 outside the trangale and test");
    Point p3(1.0f, 2.0f);
    check_point(a, b, c, p3);

    test("test case 06");
    TEST_NAME("Creating a point P4 outside the trangale and test");
    Point p4(1.0f, -1.0f);
    check_point(a, b, c, p4);

    test("test case 07");
    TEST_NAME("Creating a point P5 outside the trangale and test");
    Point p5(0.0f, 2.0f);
    check_point(a, b, c, p5);

    test("test case 08");
    TEST_NAME("Creating a point P6 outside the trangale and test");
    Point p6(7.0f, 6.0f);
    check_point(a, b, c, p6);

    test("test case 09");
    TEST_NAME("Creating a point P7 outside the trangale and test");
    Point p7(2.0f, 2.0f);
    check_point(a, b, c, p7);

    return (EXIT_SUCCESS);
}
