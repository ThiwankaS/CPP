#include "utilities.hpp"

/**
 * @brief creates a instance of zombie, name it, and return it.
 * Can use it outside of the function scope bacuse the memory allocated on heap.
 * Caller need to release the memory
 * @param name the zombie's name
 * @return Zombie*
*/
Zombie* newZombie(std::string name) {
    Zombie* z = new Zombie(name);
    return (z);
}
