#include "ScalarConverter.hpp"
#include "helper.hpp"

ScalarConverter::ScalarConverter() {
    //nothing doing here
}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    (void)other;
    //nothing doing here
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    //nothing doing here
    return (*this);
}

ScalarConverter::~ScalarConverter() {
    //nothing doing here
}

void ScalarConverter::convert(const std::string& arg) {
    switch (which_type(arg))
    {
        case Special:
            handle_special(arg);
            break;
        case Char_literal:
            handle_char_literal(arg);
            break;
        case Whole_number:
            handle_whole_number(arg);
            break;
        case Fractional_number:
            handle_fractional_number(arg);
            break;
        case Scientific_notation:
            handle_scientific_notaion(arg);
            break;
        default:
            handle_invalid(arg);
    }
}
