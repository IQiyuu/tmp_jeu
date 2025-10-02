#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "AClickableWidget.hpp"

class Button : public AClickableWidget {
    public:
        Button(
            int x = 0, 
            int y = 0,
            int width = 100,
            int height = 100,
            const std::function<void()>& action = nullptr,
            std::string text = ""
        );
        Button(const Button& other);
        ~Button(void);

        Button& operator=(const Button& other);

        void render(SDL_Renderer* renderer) const;
};

#endif
