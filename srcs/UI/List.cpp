#include "List.hpp"
#include <SDL2/SDL.h>

List::List(int x, int y, int w, int h, const std::function<void(void)>& action, const std::string& text)
    : AClickableWidget(x, y, w, h), _text(x, y, text) {
    this->_action = action;
    this->_list.push_back(Text(x + 50, y + 50, "1024x800"));
    this->_list.push_back(Text(x + 100, y + 100, "500x500"));
}

List::List(const List& other)
    : AClickableWidget(other), _text(other._text) {}

List::~List() {
    std::cout << DEBUG << " Deleting List" << std::endl;
}

List& List::operator=(const List& other) {
    if (this != &other) {
        AClickableWidget::operator=(other);
        this->_text = other._text;
    }
    return *this;
}

void List::render(SDL_Renderer* renderer) const {
    if (!this->_active) return;

    std::cout << DEBUG << " Displaying List" << std::endl;

    SDL_Rect rect = {this->_x, this->_y, this->_width, this->_height};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    this->_text.render(renderer);
}

void List::hide(SDL_Renderer* renderer) const {
    if (!this->_active) return;

    std::cout << DEBUG << " Hiding List" << std::endl;

    SDL_Rect rect = {this->_x, this->_y, this->_width, this->_height};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}