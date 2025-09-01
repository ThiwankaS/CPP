#include "Fixed.hpp"

class Point {

    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float a, const float b);
        Point(const Point& other);
        Point& operator=(const Point&);
        ~Point();

        const Fixed& getX(void) const;
        const Fixed& getY(void) const;
};

std::ostream& operator<<(std::ostream& os, const Point& point);
