#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "AClickableWidget.hpp"
#include <SDL2/SDL.h>

class Button : public AClickableWidget {
    public:
        Button(int x = 0, int y = 0, int width = 100, int height = 100, const std::function<void()>& action = nullptr);
        Button(const Button& other);
        ~Button(void);

        Button& operator=(const Button& other);

        void render(SDL_Renderer* renderer) const;
};

#endif
