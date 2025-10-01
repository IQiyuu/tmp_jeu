#ifndef COORD_HPP
#define COORD_HPP

#include <iostream>

class Coord {
    private:
        int _x;
        int _y;
    
    public:
        Coord(void);
        Coord(int, int);

        void setX(int);
        void setY(int);
        void setCoords(int,int);
        void setCoords(Coord);

        Coord getCoords(void);
        int getX(void);
        int getY(void);
};

#endif