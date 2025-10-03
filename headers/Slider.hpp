#pragma once

#include "AClickableWidget.hpp"

class Slider: public AClickableWidget {
    private:
        Text    _text;
        Text    _value;

    public:
        Slider(
            int x = 0,
            int y = 0,
            int width = 100,
            int height = 100,
            const std::function<void()>& action = {},
            const std::string& text = "",
            const std::string& text2 = "50"
        );
        Slider(const Slider& other);
        ~Slider();

        Slider& operator=(const Slider& other);

        void render(SDL_Renderer* renderer) const;
        void hide(SDL_Renderer* renderer) const;
};