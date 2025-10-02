#ifndef MENU_HPP
#define MENU_HPP

#include "Panel.hpp"

class Menu {
    private:
        std::vector<Panel *>   _panels;

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
};

#endif