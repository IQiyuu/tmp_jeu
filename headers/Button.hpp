#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Coord.hpp"

class Button {
    private:
        Coord   _coord;
        void    *_action;
        int     _height;
        int     _width;

    public:
        Button(void);
        Button(Coord _coord, void* _action = nullptr, int _width = 100, int _height = 100);
        Button(int, int, void* _action = nullptr, int _width = 100, int _height = 100);

        void    setCoord(Coord);
        void    setAction(void *);
        Coord   getCoord(void);
        void    *getAction(void);
};

#endif