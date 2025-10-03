#include "Text.hpp"

Text::Text(int x, int y, const std::string& content)
    : _x(x), _y(y), _content(content), _font(nullptr)
{
    TTF_Init();
    this->_font = TTF_OpenFont("assets/Ubuntu-B.ttf", 24);
    if (!this->_font) std::cerr << "Font load error: " << TTF_GetError() << std::endl;
}

Text::Text(const Text& other)
    : _x(other._x), _y(other._y), _content(other._content), _font(other._font) {}

Text::~Text() {
    std::cout << DEBUG << " Deleting Text" << std::endl;
    if (this->_font) TTF_CloseFont(this->_font);
}

Text& Text::operator=(const Text& other) {
    if (this != &other) {
        this->_x = other._x;
        this->_y = other._y;
        this->_content = other._content;
        this->_font = other._font;
    }
    return *this;
}

void Text::render(SDL_Renderer *renderer) const {
    if (!renderer || !this->_font) return;
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surf = TTF_RenderText_Solid(this->_font, this->_content.c_str(), color);
    if (!surf) return;

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    if (!tex) return;

    SDL_Rect dst = {this->_x, this->_y, 0, 0};
    SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, tex, nullptr, &dst);
    SDL_DestroyTexture(tex);
}

void Text::setContent(const std::string& content) {
    _content = content;
}
