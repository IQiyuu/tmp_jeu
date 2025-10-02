#ifndef TEXT_HPP
#define TEXT_HPP

#include <SDL2/SDL_ttf.h>

class Text {
    private:
        SDL_FONT    *_font;

    public:
        Text(void);
        ~Text(void);
};

#endif