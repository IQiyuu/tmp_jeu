#ifndef AWIDGET_HPP
#define AWIDGET_HPP

#include "Coord.hpp"
#include <SDL2/SDL.h>

class AWidget {
protected:
    Coord _coord;
    int _width;
    int _height;
    bool _active;

public:
    AWidget(void);
    AWidget(const Coord &coord, int width = 100, int height = 100, bool active = true);
    virtual ~AWidget(void);

    virtual void render(SDL_Renderer* renderer) const = 0;

    Coord getCoord(void) const;
    int getWidth(void) const;
    int getHeight(void) const;
    bool isActive(void) const;

    void setCoord(const Coord &c);
    void setWidth(int w);
    void setHeight(int h);
    void setActive(bool a);
    void toggleActive(void);
};

#endif
