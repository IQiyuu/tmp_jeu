#ifndef MENU_HPP
#define MENU_HPP

#include "AClickableWidget.hpp"
#include <vector>

class Menu {
    private:
        std::vector<AClickableWidget *>   _widgets;
        bool                    _active;
    
    public:
        Menu(void);
        Menu(std::vector<AClickableWidget *>);
        Menu(const Menu &);
        ~Menu(void);

        Menu &operator=(const Menu &);

        std::vector<AClickableWidget *>  getWidgets(void) const;
        std::vector<AClickableWidget *>  getActiveWidgets(void) const;
        std::vector<AClickableWidget *>  getInactiveWidgets(void) const;

        void                    addWidget(AClickableWidget *);

};

#endif