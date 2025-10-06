#pragma once

#include "AClickableWidget.hpp"
#include "Text.hpp"
#include <functional>

class Box : public AClickableWidget {
    private:
        Text _text;
        bool _check;
    public:
        Box(
            int x = 0,
            int y = 0,
            int width = 100,
            int height = 100,
            const std::function<void(void)>& action = {},
            const std::string& text = ""
        );
        Box(const Box& other);
        ~Box();

        Box& operator=(const Box& other);

        void    setChecked(bool);
        bool    getCheck(void) const;

        void render(SDL_Renderer* renderer) const;
        void hide(SDL_Renderer* renderer) const;

};