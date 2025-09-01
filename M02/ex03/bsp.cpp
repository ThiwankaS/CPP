#include "Point.hpp"

Fixed cross(const Point& a, const Point& b, const Point& c) {
    return (
        ((b.getX() - a.getX()) * (c.getY() - a.getY()))
        -((b.getY() - a.getY()) * (c.getX() - a.getX()))
    );
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    Fixed zero(0.0f);

    if (cross(a,b,c) == zero)
        return (false);
    Fixed c1 = cross(a, b, point);
    Fixed c2 = cross(b, c, point);
    Fixed c3 = cross(c, a, point);
    // if point lies on any edge
    if(c1 == zero || c2 == zero || c3 == zero)
        return (false);
    // if trangle is oriented clockwise
    if (c1 < zero && c2 < zero && c3 < zero)
        return (true);
    // if trangle is oriented counter-clockwise
    if (c1 > zero && c2 > zero && c3 > zero)
        return (true);
    return (false);
}

void check_point(Point const a, Point const b, Point const c, Point const point) {
    std::cout << "Point : ";
    std::cout << point;
    if(bsp(a, b, c, point)) {
        std::cout << " inside the triangle !\n";
    } else {
        std::cout << " outside the triangle !\n";
    }
}
