#pragma once

#include "Coord.hpp"
#include "Text.hpp"

class IWidget {
    protected:
        int _x;
        int _y;
        int _height;
        int _width;
        bool _active;
        Text _text;

    public:
        IWidget(void)
            : _x(0), _y(0), _height(100), _width(100), _active(true), _text(0, 0, "") {}
        virtual ~IWidget(void) = default;

        virtual void render(SDL_Renderer* renderer) const = 0;

        int getX(void) const { return _x; }
        int getY(void) const { return _y; }
        int getHeight(void) const { return _height; }
        int getWidth(void) const { return _width; }
        bool isActive(void) const { return _active; }
        Text& getText(void) { return _text; }
        const Text& getText(void) const { return _text; }

        void setX(int x) { _x = x; }
        void setY(int y) { _y = y; }
        void setHeight(int h) { _height = h; }
        void setWidth(int w) { _width = w; }
        void toggleActive(void) { _active = !_active; }
        void setActive(void) { _active = true; }
        void setInactive(void) { _active = false; }
        void setText(const Text& text) { _text = text; }
};
