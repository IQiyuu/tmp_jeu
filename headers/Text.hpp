#ifndef TEXT_HPP
#define TEXT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>

class Text {
    private:
        int _x;
        int _y;
        std::string _content;
        TTF_Font* _font;
        SDL_Texture* _texture;

    public:
        Text(int x = 0, int y = 0, const std::string& content = "", SDL_Renderer* renderer = nullptr);
        Text(const Text& other);
        ~Text();

        Text& operator=(const Text& other);

        void render(SDL_Renderer* renderer);
        void setContent(const std::string& content);
};

#endif
