#include "Harl.hpp"

// initiating complains array
const Levels Harl::complains[] = {
    {"DEBUG", &Harl::debug},
    {"INFO", &Harl::info},
    {"WARNING", &Harl::warning},
    {"ERROR", &Harl::error}
};

// implementing default constructor
Harl::Harl () {
    std::cout << "Default constructor [Harl] called. \n";
}

// implementing default destructor
Harl::~Harl() {
    std::cout << "Default destructor [Harl] called. \n";
}

/**
 * @brief will call the funtion base on the level, key pair values stored in the
 * complains array
 * @param level pre-defined could be "DEBUG", "INFO" , "WARNING" or "ERROR". Will dislay
 * an error message for a function call with in correct level
*/
void Harl::complain(std::string level) {

    const Levels* begin = complains;
    const Levels* end   = complains + size;

    for(const Levels* it = begin;it != end; it++) {
        if(level == it->level) {
            (this->*(it->fn))();
            return ;
        }
    }
    std::cerr << "Undefined complain level !\n";
}

// implementing debug method
void Harl::debug(void) {
    std::cout << "[DEBUG] \n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n";
    std::cout << "I really do! \n";
}

// implementing info method
void Harl::info(void) {
    std::cout << "[INFO] \n";
    std::cout << "I cannot believe adding extra bacon costs more money.\n";
    std::cout << "You didn’t put enough bacon in my burger!\n";
    std::cout << "If you did, I wouldn’t be asking for more! \n";
}

// implementing warning method
void Harl::warning(void) {
    std::cout << "[WARNING] \n";
    std::cout << "I think I deserve to have some extra bacon for free.\n";
    std::cout << "I’ve been coming for  years whereas you started working here since last month.\n";
}

// implementing error method
void Harl::error(void) {
    std::cout << "[ERROR] \n";
    std::cout << "This is unacceptable! I want to speak to the manager now. \n";
}
