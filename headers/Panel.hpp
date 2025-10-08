#pragma once

#include "AClickableWidget.hpp"
#include <vector>

class Panel {
    private:
        std::vector<AClickableWidget *> _widgets;
        std::string                     _name;
        bool                            _active;
        int                             _x;
        int                             _y;
        int                             _w;
        int                             _h;

    public:
        Panel(int x = 0, int y = 0, int w = 1024, int h = 800);
        Panel(std::vector<AClickableWidget *>);
        Panel(const Panel &);
        ~Panel(void);

        Panel &operator=(const Panel &);

        std::string                      getName(void) const;
        std::vector<AClickableWidget *>  getWidgets(void) const;
        std::vector<AClickableWidget *>  getActiveWidgets(void) const;
        std::vector<AClickableWidget *>  getInactiveWidgets(void) const;
        bool                             isActive(void) const;
        int                              getX(void) const;
        int                              getY(void) const;
        int                              getWidth(void) const;
        int                              getHeight(void) const;

        void                             disable();
        void                             enable();
        void                             setName(std::string);

        void                    addWidget(AClickableWidget *);
        void                    addWidgets(std::vector<AClickableWidget *>);
        void                    enableAll(SDL_Renderer *);
        void                    disableAll(SDL_Renderer *);

        void                    display(SDL_Renderer *r);
        void                    hide(SDL_Renderer *r);

};
