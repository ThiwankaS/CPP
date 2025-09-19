#include "helper.hpp"

Type which_type(const std::string& arg) {
    if(is_special(arg))
        return (Special);
    if(is_char_literal(arg))
        return (Char_literal);
    if(is_whole_number(arg))
        return (Whole_number);
    if(is_fractional_number(arg))
        return (Fractional_number);
    if(is_scientific_notaion(arg))
        return(Scientific_notation);
    return(Invalid_argument);
}

bool is_special(const std::string& arg) {
    return (
        arg == "nan"
     || arg == "nanf"
     || arg == "inf"
     || arg == "inff"
     || arg == "+inf"
     || arg == "+inff"
     || arg == "-inf"
     || arg == "-inff"
    );
}

bool is_char_literal(const std::string& arg) {
    return (std::regex_match(arg, char_literal));
}

bool is_whole_number(const std::string& arg) {
    return (std::regex_match(arg, whole_number));
}

bool is_fractional_number(const std::string& arg) {
    return (std::regex_match(arg, fraction_number));
}

bool is_scientific_notaion(const std::string& arg) {
    return (std::regex_match(arg, scientific_notation));
}

void handle_special(const std::string& arg) {
    std::cout << "char      : impossible" << std::endl;
    std::cout << "int       : impossible" << std::endl;
    if(arg == "nan" || arg == "nanf") {
        std::cout << "float     : nanf" << std::endl;
        std::cout << "double    : nan"  << std::endl;
    }
    if(arg == "inf" || arg == "inff" || arg == "+inf" || arg == "+inff") {
        std::cout << "float     : +inff" << std::endl;
        std::cout << "double    : +inf"  << std::endl;
    }
        if(arg == "-inf" || arg == "-inff") {
        std::cout << "float     : -inff" << std::endl;
        std::cout << "double    : -inf"  << std::endl;
    }
}

void handle_char(int value) {
    if(value >= 32 && value <= 126 )
        std::cout << "char      : " << static_cast<char>(value) << std::endl;
    if((value >= 0 && value < 32) || value == 127)
        std::cout << "char      : Non displayable"  << std::endl;
    if(value > 127 && value <= 255)
        std::cout << "char      : Not include in std ASCII"  << std::endl;
    if(value < 0 || value > 255)
        std::cout << "char      : impossible"  << std::endl;
}

void handle_int(double value) {
    if(value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()){
        handle_char(static_cast<int>(value));
        std::cout << "int       : " << static_cast<int>(value) << std::endl;
    } else {
        std::cout << "char      : impossible" << std::endl;
        std::cout << "int       : impossible" << std::endl;
    }            
}

void handel_float(double value) {
    if(value >= std::numeric_limits<float>::lowest() && value <= std::numeric_limits<float>::max()) {
        float f_value = static_cast<float>(value);
        if (value == floor(f_value) && f_value != std::numeric_limits<float>::infinity()) {
            std::cout << "float     : " << std::fixed << std::setprecision(1) << f_value << "f" << std::endl;   
        } else {
            std::cout << "float     : " << f_value << "f" << std::endl;
        }
    } else {
        std::cout << "float     : impossible" << std::endl;
    }
}
 
void handle_char_literal(const std::string& arg) {
    char c;

    arg.length() == 3 ? c = arg[1] : c = arg[0];

    int value = static_cast<int>(c);
    handle_char(value);
    std::cout << "int       : " << value << std::endl;
    std::cout << "float     : " << static_cast<float>(c) << std::endl;
    std::cout << "double    : "  << static_cast<double>(c) << std::endl;
}

void handle_whole_number(const std::string& arg) {
    try {
            double value = std::stod(arg);
            handle_int(value);
            handel_float(value);
            std::cout << "double    : " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "char      : impossible" << std::endl;
        std::cout << "int       : impossible" << std::endl;
        std::cout << "float     : impossible" << std::endl;
        std::cout << "double    : impossible" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "invalid argument : " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "unexpected error occured : " << e.what() << std::endl;
    }
}

void handle_fractional_number(const std::string& arg) {
    try {
            double value = std::stod(arg);
            handle_int(value);
            handel_float(value);
            std::cout << "double    : " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "char      : impossible" << std::endl;
        std::cout << "int       : impossible" << std::endl;
        std::cout << "float     : impossible" << std::endl;
        std::cout << "double    : impossible" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "invalid argument : " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "unexpected error occured : " << e.what() << std::endl;
    }
}

void handle_scientific_notaion(const std::string& arg) {
    try {
            double value = std::stod(arg);
            handle_int(value);
            handel_float(value);
            std::cout << "double    : " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "char      : impossible" << std::endl;
        std::cout << "int       : impossible" << std::endl;
        std::cout << "float     : impossible" << std::endl;
        std::cout << "double    : impossible" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "invalid argument : " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "unexpected error occured : " << e.what() << std::endl;
    }
}

void handle_invalid(const std::string& arg) {
    std::cerr << "invalid argument : (" << arg << ")" << std::endl;
}
