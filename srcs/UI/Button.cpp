#include "Button.hpp"
#include <SDL2/SDL.h>

Button::Button(int x, int y, int w, int h, const std::function<void()>& action, const std::string& text)
    : AClickableWidget(x, y, w, h), _text(x, y, text) {
    this->_action = action;
}

Button::Button(const Button& other)
    : AClickableWidget(other), _text(other._text) {}

Button::~Button() {
    std::cout << "Button load error: " << std::endl;
}

Button& Button::operator=(const Button& other) {
    if (this != &other) {
        AClickableWidget::operator=(other);
        this->_text = other._text;
    }
    return *this;
}

void Button::render(SDL_Renderer* renderer) const {
    if (!this->_active) return;

    SDL_Rect rect = {this->_x, this->_y, this->_width, this->_height};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    this->_text.render(renderer);
}
