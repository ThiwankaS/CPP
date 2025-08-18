#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

// forward declaration of a class
class Harl;

// creating {"Level", "functionPTR"} pairs
struct Levels {
    const std::string level;
    void (Harl::*fn)(void);
};

class Harl {

    private:
        // class members
        static constexpr int size = 4;
        static const Levels complains[size];
        // private functions
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        // Default constructor
        Harl();
        // Default destructor
        ~Harl();
        /**
         * both copy constructor and assignment constructor has removed,
         * because static members are shared accross all the objects
         * so make the class explicitly non-copyable
        */
        Harl(const Harl& other)=delete;
        Harl& operator=(const Harl& other)=delete;
        // class methods
        void complain(std::string level);
};

#endif
