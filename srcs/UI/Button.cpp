#include "Button.hpp"

Button::Button(void) : _coord(Coord()), _action(nullptr), _height(100), _width(100), _active(true) {
    std::cout << "Button created at coords (100,100)" << std::endl;
}

Button::Button(Coord coord, void (*action)(void), int width, int height)
    : _coord(coord), _action(action), _height(height), _width(width), _active(true) {
    std::cout << "Button created at coords (" 
              << _coord.getX() << "," << _coord.getY() << ")" << std::endl;
}

Button::Button(int x, int y, void (*action)(void), int width, int height)
    : _coord(Coord(x,y)), _action(action), _height(height), _width(width), _active(true) {
    std::cout << "Button created at coords (" 
              << _coord.getX() << "," << _coord.getY() << ")" << std::endl;
}

int     Button::getHeight(void) { return this->_height; }
int     Button::getWidth(void) { return this->_width; }
Coord   Button::getCoord(void) { return this->_coord; }
void    (*Button::getAction(void))(void) { return this->_action; }
bool    Button::getActive(void) { return this->_active; }

void    Button::setHeight(int h) { this->_height = h; }
void    Button::setWidth(int w) { this->_width = w; }
void    Button::setAction(void (*a)(void)) { this->_action = a; }
void    Button::setCoord(Coord c) { this->_coord = c; }
void    Button::setActive(void) { this->_active = !this->_active; }

void    Button::render(SDL_Renderer *canvas) {
    SDL_SetRenderDrawColor(canvas, 255, 0, 0, 255);
    SDL_Rect rect;
    rect.x = this->_coord.getX();
    rect.y = this->_coord.getY();
    rect.w = this->_width;
    rect.h = this->_height;
    SDL_RenderFillRect(canvas,&rect);
}