#include "Coord.hpp"

Coord::Coord(void) : _x(0), _y(0) {}
Coord::Coord(int x, int y) : _x(x), _y(y) {}
Coord::Coord(const Coord &c) : _x(c._x), _y(c._y) {}
Coord::~Coord(void) {}

Coord& Coord::operator=(const Coord &other) {
    if (this != &other) {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}

void Coord::setX(int x) { _x = x; }
void Coord::setY(int y) { _y = y; }
void Coord::setCoords(int x, int y) { _x = x; _y = y; }
void Coord::setCoords(const Coord &c) { _x = c._x; _y = c._y; }

int Coord::getX(void) const { return _x; }
int Coord::getY(void) const { return _y; }
Coord Coord::getCoords(void) const { return *this; }
