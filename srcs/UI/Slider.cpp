#include "Slider.hpp"
#include <SDL2/SDL.h>

Slider::Slider(int x, int y, int w, int h, const std::function<void(void)>& action, const std::string& text, const std::string& text2)
    : AClickableWidget(x, y, w, h), _text(x-50, y-25, text), _value(x, y, text2) {
    this->_action = action;
}

Slider::Slider(const Slider& other)
    : AClickableWidget(other), _text(other._text) {}

Slider::~Slider() {
    std::cout << DEBUG << " Deleting Slider" << std::endl;
}

Slider& Slider::operator=(const Slider& other) {
    if (this != &other) {
        AClickableWidget::operator=(other);
        this->_text = other._text;
    }
    return *this;
}

void Slider::render(SDL_Renderer* renderer) const {
    if (!this->_active) return;
    std::cout << DEBUG << " Displaying Slider" << std::endl;

    int v = std::stoi(this->_value.getContent());

    SDL_Rect rect = {this->_x, this->_y, this->_width, this->_height};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_Rect filled = {this->_x, this->_y, this->_width * v / 100, this->_height};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &filled);

    SDL_Rect empty = {this->_x + this->_width * v / 100, this->_y, this->_width * (100 - v) / 100, this->_height};
    SDL_SetRenderDrawColor(renderer, 173, 216, 230, 255);
    SDL_RenderFillRect(renderer, &empty);

    this->_text.render(renderer);
    //this->_value.render(renderer);
}


void Slider::hide(SDL_Renderer* renderer) const {
    if (!this->_active) return;

    std::cout << DEBUG << " Hiding Slider" << std::endl;

    SDL_Rect rect = {this->_x, this->_y, this->_width, this->_height};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void    Slider::setValue(const std::string &v) { this->_value.setContent(v); }