#include "DropDown.hpp"
#include <SDL2/SDL.h>

DropDown::DropDown(int x, int y, int w, int h, const std::function<void(void)>& action, const std::string& text)
    : AClickableWidget(x, y, w, h), _text(x-50, y-25, text), _isDropDown(false) {
    this->_action = action;
    Text *t = new Text(x, y, "1024x800");
    this->_list.push_back(t);
    t = new Text(x, y + 50, "500x500");
    this->_list.push_back(t);
}

DropDown::DropDown(const DropDown& other)
    : AClickableWidget(other), _text(other._text) {}

DropDown::~DropDown() {
    std::cout << DEBUG << " Deleting DropDown" << std::endl;
    for (auto &t : this->_list)
        delete t;
}

DropDown& DropDown::operator=(const DropDown& other) {
    if (this != &other) {
        AClickableWidget::operator=(other);
        this->_text = other._text;
    }
    return *this;
}

bool DropDown::execute(void) {
    if (this->_action) this->_action();
    return true;
}

void    DropDown::setDropDown(bool a) { this->_isDropDown = a; }
bool    DropDown::getDropDown(void) const { return this->_isDropDown; }

void DropDown::render(SDL_Renderer* renderer) const {
    if (!this->_active) return;
    this->hide(renderer);

    std::cout << DEBUG << " Displaying DropDown " << _isDropDown << std::endl;

    if (this->_isDropDown) {
        std::cout << DEBUG << " Displaying DropDown " << _isDropDown << std::endl;
        for (auto &t : this->_list) {
            SDL_Rect rect = {this->_x, t->getY(), this->_width, this->_height};
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_RenderFillRect(renderer, &rect);

            t->render(renderer);
        }
    } else {
        Text *t = this->_list.front();
        SDL_Rect rect = {this->_x, t->getY(), this->_width, this->_height};
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderFillRect(renderer, &rect);

        t->render(renderer);
    }
        
    this->_text.render(renderer);
}

void DropDown::hide(SDL_Renderer* renderer) const {
    if (!this->_active) return;

    std::cout << DEBUG << " Hiding DropDown" << std::endl;

    SDL_Rect rect = {this->_x, this->_y, this->_width, this->_height};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}