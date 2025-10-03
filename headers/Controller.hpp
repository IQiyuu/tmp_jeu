#pragma once

#include "Menu.hpp"
#include "Button.hpp"
#include "Save.hpp"
#include "Settings.hpp"
#include "Slider.hpp"

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

        Save            save;
        Settings        settings;
    
    public:
        Controller(void);
        ~Controller(void);

        Menu            *getMainMenu(void) const;
        SDL_Renderer    *getRenderer() const;
};
