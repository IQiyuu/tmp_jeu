#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "AClickableWidget.hpp"
#include "Text.hpp"
#include <functional>
#include <string>

class Button : public AClickableWidget {
    private:
        Text _text;
    public:
        Button(
            int x = 0,
            int y = 0,
            int width = 100,
            int height = 100,
            const std::function<void()>& action = {},
            const std::string& text = ""
        );
        Button(const Button& other);
        ~Button();

        Button& operator=(const Button& other);

        void render(SDL_Renderer* renderer) const;
        void hide(SDL_Renderer* renderer) const;

};

#endif
