#include "utilities.hpp"

/**
 * @brief will create an instance of Zombie with the name, and invoke the announce
 * function of the respective instance
 * @param name Zombie's name
*/
void randomChump( std::string name ) {
    Zombie z = Zombie(name);
    z.announce();
}
