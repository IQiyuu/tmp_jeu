#ifndef IWIDGET_HPP
#define IWIDGET_HPP

#include "Coord.hpp"
#include <SDL2/SDL.h>

class IWidget {
protected:
    Coord _coord;
    int _height;
    int _width;
    bool _active;

public:
    IWidget(void) : _coord(0,0), _height(100), _width(100), _active(true) {}
    virtual ~IWidget(void) = default;

    virtual void render(SDL_Renderer* renderer) const = 0;

    Coord getCoord(void) const { return _coord; }
    int getHeight(void) const { return _height; }
    int getWidth(void) const { return _width; }
    bool isActive(void) const { return _active; }

    void setCoord(const Coord& c) { _coord = c; }
    void setHeight(int h) { _height = h; }
    void setWidth(int w) { _width = w; }
    void toggleActive(void) { _active = !_active; }
};

#endif
