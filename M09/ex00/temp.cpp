#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
    if(argc == 2) {
        std::stringstream obj(argv[1]);
        int year, month, date;
        char dash;
        obj >> year >> dash >> month >> dash >> date;
        std::cout << year + 1 << month + 1 << date + 2 << std::endl;
    }
    return (EXIT_SUCCESS);
}
