#include <iostream>
#include <string>

#include "test.hpp"

int main(void) {

    test("test case 01");
    TEST_NAME("Creating and initialing variables");
    LINE_DATA;
    std::string  sentence = "HI THIS IS BRAIN";
    std::string* stringPTR = &sentence;
    std::string& stringREF = sentence;
    std::cout << " varibales sentence, stringPTR and stringREF sucessfully declared and initialized \n";
    LINE_DATA;

    test("test case 02");
    TEST_NAME("Displaying memory address of each variable");
    LINE_DATA;
    std::cout << "memory address of sentence  : "
        << static_cast<const void*>(&sentence)
    << std::endl;
    std::cout << "memory address of stringPTR : "
        <<  static_cast<const void*>(&stringPTR)
    << std::endl;
    std::cout << "memory address of stringREF : "
        <<  static_cast<const void*>(&stringREF)
    << std::endl;
    LINE_DATA;

    test("test case 03");
    TEST_NAME("Displaying values stored in each varibale");
    LINE_DATA;
    std::cout << "value of sentence  : "
        << sentence
    << std::endl;
    std::cout << "value of stringPTR : "
        <<  *stringPTR
    << std::endl;
    std::cout << "value of stringREF : "
        <<  stringREF
    << std::endl;
    LINE_DATA;

    test("test case 04");
    TEST_NAME("Change the initial value to \"HI THIS IS HEART\"");
    LINE_DATA;
    sentence = "HI THIS IS HEART";
    std::cout << "value of sentence  : "
        << sentence
    << std::endl;
    std::cout << "value of stringPTR : "
        <<  *stringPTR
    << std::endl;
    std::cout << "value of stringREF : "
        <<  stringREF
    << std::endl;
    LINE_DATA;

    test("test case 05");
    TEST_NAME("Displaying memory addresses after change");
    LINE_DATA;
    std::cout << "memory address of sentence  : "
        << static_cast<const void*>(&sentence)
    << std::endl;
    std::cout << "memory address of stringPTR : "
        <<  static_cast<const void*>(&stringPTR)
    << std::endl;
    std::cout << "memory address of stringREF : "
        <<  static_cast<const void*>(&stringREF)
    << std::endl;
    LINE_DATA;

    return (0);
}
