#include "Point.hpp"

// default constructor
Point::Point() : x(0.0f), y (0.0f) {}
// two argument constructor
Point::Point(const float a, const float b) : x(a), y(b) {}
// copy constructor
Point::Point(const Point& other) : x(other.getX()), y (other.getY()) {}
// assigment aoperator :- doing nothing
Point& Point::operator=(const Point&) { return (*this); }
// default destructor
Point::~Point() {}
// getting the value x
const Fixed& Point::getX(void) const { return (this->x); }
// getting the value y
const Fixed& Point::getY(void) const { return (this->y); }
// << operator oveloading
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "[" << point.getX() << "," << point.getY()<<"]";
    return (os);
}
