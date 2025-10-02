#include "Button.hpp"

// ===== Constructeurs / destructeur =====
Button::Button(void) : AWidget(), _action(nullptr) {}

Button::Button(const Coord &coord, void (*action)(void), int width, int height)
    : AWidget(coord, width, height), _action(action) {}

Button::Button(int x, int y, void (*action)(void), int width, int height)
    : AWidget(Coord(x,y), width, height), _action(action) {}

Button::Button(const Button &b) : AWidget(b), _action(b._action) {}

Button::~Button(void) {}

Button& Button::operator=(const Button &b) {
    if (this != &b) {
        AWidget::operator=(b); // copie les membres hérités
        _action = b._action;
    }
    return *this;
}

void Button::setAction(void (*a)(void)) { _action = a; }
void (*Button::getAction(void) const)(void) { return _action; }

void Button::render(SDL_Renderer *canvas) const {
    SDL_SetRenderDrawColor(canvas, 255, 0, 0, 255);
    SDL_Rect rect;
    rect.x = _coord.getX();
    rect.y = _coord.getY();
    rect.w = _width;
    rect.h = _height;
    SDL_RenderFillRect(canvas, &rect);
}
