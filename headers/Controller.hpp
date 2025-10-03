#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Menu.hpp"
#include "Button.hpp"

enum States {
    MAIN_MENU,
    GAME_MENU,
    GAME
};

const int WIDTH = 1024;
const int HEIGHT = 800;

class Controller {
    private:
        Menu            *_main_menu;
        Menu            *_game_menu;
        int             _state;
        TTF_Font        *_font;
        SDL_Window      *_window;
        SDL_Renderer    *_renderer;
    
    public:
        Controller(void);
        ~Controller(void);

        Menu            *getMainMenu(void) const;
        SDL_Renderer    *getRenderer() const;
};

#endif