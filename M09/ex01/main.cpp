#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        try {
            RPN rpn;
            rpn.process(argv[1]);
            rpn.displayAnswere();
        } catch (const std::exception& e) {
            std::cerr << "Error "<< std::endl;
            std::cerr << e.what() << std::endl;
        }
    }
    return (EXIT_SUCCESS);
}
