#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[]) {
    /**
     * varibale declaration, for string compiler it self intialize to value NULL
     */
    std::string argument;

    if (argc > 1)
    {
        /**
         * the outer for loop is iterating through the command line argument
         * array starting from 01st element to last element
         */
        for(int i = 1; i < argc ; i++) {
            /**
             * prevent appending everyting again and again by reset the value of argument
             * varibale at the start of the every word
             */
            argument.clear();
            /**
             * this inner for loop iterating through each character in the
             * command line argument array and apps to the toupper() function
             * using argv[i][j]
            */
            for(int j = 0; argv[i][j] != '\0'; j++) {
            /**
             * a string will build character by character after convert it to
             * uppercase
            */
                argument += static_cast<char>(std::toupper(argv[i][j]));
            }
            /**
             * printing argument
            */
            std::cout << argument;
            /**
             * a blank space will print in between two consecutive arguments
             * if the argument is not the last one
            */
            if(i < (argc - 1))
                std::cout << " ";
        }
        std::cout << "\n";
    } else {
        /**
         * fall back statement when the program invoke with out any command line
         * argument
         */
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return(0);
}
