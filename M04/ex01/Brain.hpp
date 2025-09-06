#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define SIZE 100

class Brain {

    private:
        std::string ideas[SIZE];

    public:
        Brain();
        Brain(const std::string& idea);
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        virtual ~Brain();

        void setIdeas(const std::string& idea);
        void showAllIdeas(void) const;
};

#endif
