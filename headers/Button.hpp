#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Coord.hpp"
#include <SDL2/SDL.h>

class Button {
    private:
        Coord   _coord;
        void (*_action)(void);
        int     _height;
        int     _width;
        bool    _active;

    public:
        Button(void);
        Button(Coord _coord, void (*_action)(void) = nullptr, int _width = 100, int _height = 100);
        Button(int, int, void (*_action)(void) = nullptr, int _width = 100, int _height = 100);

        void    setCoord(Coord);
        void    setActive(void);
        void    setAction(void (*a)(void));
        void    setWidth(int);
        void    setHeight(int);
        Coord   getCoord(void);
        void    (*getAction(void))(void);
        bool    getActive(void);
        int     getWidth(void);
        int     getHeight(void);

        void    render(SDL_Renderer *); // a mettre dans une classe graphique apart
};

#endif