#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <regex>

#include "CustomeExcpetion.hpp"

#define HIGLIGHT_START	"\x1b[1m\x1b[38;2;0;0;0m\x1b[48;2;255;255;170m"
#define HIGLIGHT_END	"\x1b[0m"
#define VALID_FORMAT "^(\\d|[+\\-*/])$"

class RPN {
    private:
        std::stack<int>buffer;
        int answere;
        const std::regex valid_format;

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other) = delete;
        ~RPN();

        struct InvalidElement : public CustomeException {
            InvalidElement(const std::string& str):
                CustomeException(str) {}
        };

        struct UndefineOperation : public CustomeException {
            UndefineOperation(const std::string& str):
                CustomeException(str){}
        };

        int evaluate(int a, int b, char optr);
        void process(const std::string& input);
        bool isValidToken(const std::string& tokne);
        bool isNumber(const std::string& token);
        void displayAnswere(void);
        int getAnswere(void);
        void print(int i);
};
