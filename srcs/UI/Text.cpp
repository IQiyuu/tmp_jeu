#include "Text.hpp"

Text::Text(int x, int y, const std::string& content, SDL_Renderer* renderer)
    : _x(x), _y(y), _content(content), _font(nullptr), _texture(nullptr)
{
    if (renderer) {
        TTF_Init();
        _font = TTF_OpenFont("path_to_font.ttf", 24); // Remplace par ton chemin de font
        if (!_font) std::cerr << "Font load error: " << TTF_GetError() << std::endl;
        // tu peux créer la texture ici si nécessaire
    }
}

Text::Text(const Text& other)
    : _x(other._x), _y(other._y), _content(other._content), _font(other._font), _texture(other._texture) {}

Text::~Text() {
    if (_texture) SDL_DestroyTexture(_texture);
    if (_font) TTF_CloseFont(_font);
}

Text& Text::operator=(const Text& other) {
    if (this != &other) {
        _x = other._x;
        _y = other._y;
        _content = other._content;
        _font = other._font;
        _texture = other._texture;
    }
    return *this;
}

void Text::render(SDL_Renderer* renderer) {
    if (!renderer || !_font) return;

    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surf = TTF_RenderText_Solid(_font, _content.c_str(), color);
    if (!surf) return;

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    if (!tex) return;

    SDL_Rect dst = {_x, _y, 0, 0};
    SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, tex, nullptr, &dst);
    SDL_DestroyTexture(tex);
}

void Text::setContent(const std::string& content) {
    _content = content;
}
