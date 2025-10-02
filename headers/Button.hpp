#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "AWidget.hpp"
#include <SDL2/SDL.h>

class Button : public AWidget {
private:
    void (*_action)(void);

public:
    Button();
    Button(const Coord &coord, void (*action)(void) = nullptr, int width = 100, int height = 100);
    Button(int x, int y, void (*action)(void) = nullptr, int width = 100, int height = 100);
    Button(const Button &);
    ~Button();

    Button& operator=(const Button &);

    void setAction(void (*a)(void));
    void (*getAction() const)(void);

    void render(SDL_Renderer *canvas) const override;
};

#endif
