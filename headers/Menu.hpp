#pragma once

#include "Panel.hpp"

class SDL_Renderer;

class Menu {
    private:
        std::vector<Panel *>   _panels;
        bool                   _active;

    public:
        Menu(void);
        Menu(std::vector<Panel *>);
        Menu(const Menu &);
        ~Menu(void);

        Menu &operator=(const Menu &);

        std::vector<Panel *> getPanels(void) const;
        Panel               *getActivePanel(void) const;
        void                 addPanel(Panel *);
        void                 createPanel(void);

        bool                isActive(void) const;
        void                setActive(bool);
        void                enable(SDL_Renderer *);
        void                disable(SDL_Renderer *);
};
