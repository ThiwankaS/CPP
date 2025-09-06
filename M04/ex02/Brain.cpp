#include "Brain.hpp"

Brain::Brain() {
    setIdeas("default");
    std::cout << "Brain default constuctor called." << std::endl;
}

Brain::Brain(const std::string& idea) {
    setIdeas(idea);
    std::cout << "Brain argument construnctor called." << std::endl;
}

Brain::Brain(const Brain& other) {
    for(int i = 0; i < SIZE; i++) {
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if(this != &other) {
        for(int i = 0; i < SIZE; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Brain assignment oporator called." << std::endl;
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain destructor called." << std::endl;
}

void Brain::setIdeas(const std::string& idea) {
    for(int i = 0; i < SIZE; i++) {
        ideas[i] = idea;
    }
}

void Brain::showAllIdeas(void) const {
        for(int i = 0; i < SIZE; i++) {
        std::cout << "ideas ["
                  << i
                  << "] : "
                  << ideas[i]
                  << std::endl;
    }
}
