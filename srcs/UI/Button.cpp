#include "Button.hpp"

Button::Button(int x, int y, int width, int height, const std::function<void()>& action, std::string text)
    : AClickableWidget(x, y, width, height, true, text) {
    setAction(action);
}

Button::Button(const Button& other)
    : AClickableWidget(other) {
    _action = other._action;
}

Button::~Button(void) {}

Button& Button::operator=(const Button& other) {
    if (this != &other) {
        AClickableWidget::operator=(other);
        _action = other._action;
    }
    return *this;
}

void Button::render(SDL_Renderer* renderer) const {
    if (!_active) return;
    SDL_Rect rect = {_x, _y, _width, _height};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}
