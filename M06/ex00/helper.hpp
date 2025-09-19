#pragma once

#include <iostream>
#include <string>
#include <regex>
#include <limits>
#include <execution>
#include <iomanip>
#include <cmath>

#define CHAR_PATTERN        "^\\'.\\'|[^0-9]|\\'\\\\[fntvr]\\'$"
#define WHOLE_NUMBER        "^[+-]?[0-9]+$"
#define FRACTION_NUMBER     "^[+-]?[0-9]*\\.[0-9]+[Ff]?$"
#define SCIENTIFIC_NOTATION "^[+-]?([0-9]*\\.[0-9]+|[0-9]+)[Ee][+-]?[0-9]+$"

const std::regex char_literal           (CHAR_PATTERN);
const std::regex whole_number           (WHOLE_NUMBER);
const std::regex fraction_number        (FRACTION_NUMBER);
const std::regex scientific_notation    (SCIENTIFIC_NOTATION);

enum Type {
    Special,
    Char_literal,
    Whole_number,
    Fractional_number,
    Scientific_notation,
    Invalid_argument
};

Type which_type(const std::string& arg);

bool is_special(const std::string& arg);
bool is_char_literal(const std::string& arg);
bool is_whole_number(const std::string& arg);
bool is_fractional_number(const std::string& arg);
bool is_scientific_notaion(const std::string& arg);

void handle_special(const std::string& arg);
void handle_invalid(const std::string& arg);
void handle_char_literal(const std::string& arg);
void handle_whole_number(const std::string& arg);
void handle_fractional_number(const std::string& arg);
void handle_scientific_notaion(const std::string& arg);