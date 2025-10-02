#ifndef COORD_HPP
#define COORD_HPP

#include <iostream>

class Coord {
private:
    int _x;
    int _y;

public:
    Coord(void);
    Coord(int x, int y);
    Coord(const Coord &other);
    ~Coord(void);

    Coord& operator=(const Coord &other);

    void setX(int x);
    void setY(int y);
    void setCoords(int x, int y);
    void setCoords(const Coord &c);

    Coord getCoords() const;
    int getX() const;
    int getY() const;
};

#endif
