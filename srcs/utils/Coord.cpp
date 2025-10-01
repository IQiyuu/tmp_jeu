#include "Coord.hpp"

Coord::Coord(void): _x(0), _y(0) { std::cout << "Coords (0, 0) created" << std::endl; }

Coord::Coord(int x, int y): _x(x), _y(y) { std::cout << "Coords (" << x << "," << y << ") created" << std::endl; }

void Coord::setX(int x) { this->_x = x; }
void Coord::setY(int y) { this->_y = y; }
void Coord::setCoords(int x, int y) { this->_x = x; this->_y = y; }
void Coord::setCoords(Coord c) { this->_x = c._x; this->_y = c._y; }
int Coord::getX(void) { return this->_x; }
int Coord::getY(void) { return this->_y; }
Coord Coord::getCoords(void) { return *this; }