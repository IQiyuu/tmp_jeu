#include "Box.hpp"
#include <SDL2/SDL.h>

Box::Box(int x, int y, int w, int h, const std::function<void(void)>& action, const std::string& text)
    : AClickableWidget(x, y, w, h), _text(x, y, text), _check(false) {
    this->_action = action;
}

Box::Box(const Box& other)
    : AClickableWidget(other), _text(other._text) {}

Box::~Box() {
    std::cout << DEBUG << " Deleting Box" << std::endl;
}

Box& Box::operator=(const Box& other) {
    if (this != &other) {
        AClickableWidget::operator=(other);
        this->_text = other._text;
    }
    return *this;
}

void    Box::setChecked(bool a) { this->_check = a; }
bool    Box::getCheck(void) const { return this->_check; }

void Box::render(SDL_Renderer* renderer) const {
    if (!this->_active) return;

    std::cout << DEBUG << " Displaying Box (" << this->_x << "," << this->_y << ")" << this->_x + this->_width << ","  << this->_y + this->_height<< std::endl;

    SDL_Rect rect = {this->_x, this->_y, this->_width, this->_height};
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &rect);

    if (this->_check) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, this->_x, this->_y,  this->_x + this->_width,  this->_y + this->_height);
        SDL_RenderDrawLine(renderer, this->_x + this->_width,  this->_y, this->_x, this->_y + this->_height);
    }



    this->_text.render(renderer);
}

void Box::hide(SDL_Renderer* renderer) const {
    if (!this->_active) return;

    std::cout << DEBUG << " Hiding Box" << std::endl;

    SDL_Rect rect = {this->_x, this->_y, this->_width, this->_height};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}