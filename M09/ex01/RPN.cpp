#include "RPN.hpp"

RPN::RPN():
answere(0),
valid_format(VALID_FORMAT){}

RPN::RPN(const RPN& other):
buffer(other.buffer),
answere(other.answere),
valid_format(other.valid_format){}

RPN::~RPN() {}

bool RPN::isValidToken(const std::string& token) {
    return (std::regex_match(token, valid_format));
}

bool RPN::isNumber(const std::string& token) {
    char ch = token.at(0);
    return (std::isdigit(ch));
}

int RPN::getAnswere(void) {
    try {
            if(buffer.size() == 0 || buffer.size() > 1) {
                throw UndefineOperation("Could not resolve the expression!");
            }
            answere = static_cast<int>(buffer.top());
            buffer.pop();
            return (answere);
    } catch (const std::exception& e) {
        throw;
    }
}

void RPN::displayAnswere(void) {
    std::ostringstream out_str;

    try {
            out_str
            //<< HIGLIGHT_START
            //<< "answere : "
            << getAnswere();
            //<< HIGLIGHT_END;
        std::cout << out_str.str() << std::endl;
    } catch (const std::exception& e) {
        throw;
    }
}

int RPN::evaluate(int a, int b, char optr){
    int result = 0;

    switch (optr) {
        case '/':
            if (a == 0)
                throw UndefineOperation("Divide by zero!");
            result = b / a;
            break;
        case '*':
            result = b * a;
            break;
        case '-':
            result = b - a;
            break;
        case '+':
            result = b + a;
            break;
        default:
            throw InvalidElement("Invalid operator!");
            break;
    }
     return (result);
}

void RPN::process(const std::string& input) {
    std::istringstream obj(input);
    std::string token;
    int temp, a, b;

    while(obj >> token) {
        if(!isValidToken(token)){
            throw InvalidElement("Invalid element!");
        }
        if(isNumber(token)) {
            try {
                    temp = std::stoi(token);
                    buffer.push(temp);
            } catch (const std::exception& e) {
                throw;
            }
        } else {
            if(buffer.size() < 2) {
                throw UndefineOperation("Insufficient operands!");
            }
            a = buffer.top();
            buffer.pop();
            b = buffer.top();
            buffer.pop();
            temp = evaluate(a, b, token.at(0));
            buffer.push(temp);
        }
    }
}
