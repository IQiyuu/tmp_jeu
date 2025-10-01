#include "Button.hpp"

Button::Button(void) : _coord(Coord()), _action(nullptr), _height(100), _width(100) {
    std::cout << "Button created at coords (100,100)" << std::endl;
}

Button::Button(Coord coord, void* action, int width, int height)
    : _coord(coord), _action(action), _height(height), _width(width) {
    std::cout << "Button created at coords (" 
              << _coord.getX() << "," << _coord.getY() << ")" << std::endl;
}

Button::Button(int x, int y, void* action, int width, int height)
    : _coord(Coord(x,y)), _action(action), _height(height), _width(width) {
    std::cout << "Button created at coords (" 
              << _coord.getX() << "," << _coord.getY() << ")" << std::endl;
}
