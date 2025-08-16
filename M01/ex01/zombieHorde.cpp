#include "Zombie.hpp"
#include "utilities.hpp"

/**
 * @brief Allocate a contiguous "horde" of `N` `Zombie` objects on the heap and
 * initialize each with `name`.
 * @param N    Number of zombies to create.
 * @param name The name used to initialize each `Zombie`.
 * @return `Zombie*` Pointer to the first element of the contiguous array,
 * or `nullptr` if `N <= 0`.
 * The caller owns this memory and must release it with `delete[]`.
 */
Zombie* zombieHorde( int N, std::string name ) {

    if (N <= 0)
        return (nullptr);
    // Create a model zombie with the desired name; we'll copy-assign from it.
    Zombie patient_zero = Zombie(name);
    // Allocate a single contiguous block of N Zombies and default-construct them.
    Zombie *zombies = new Zombie[N];
    // Copy-assign the model's state into each element.
    for(int i = 0; i < N; i++) {
        zombies[i] = patient_zero;
    }
    return (zombies);
}
