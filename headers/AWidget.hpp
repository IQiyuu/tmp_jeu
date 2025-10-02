#ifndef AWIDGET_HPP
#define AWIDGET_HPP

#include "IWidget.hpp"
#include <SDL2/SDL.h>

class AWidget: public IWidget {
    protected:
        Coord _coord;
        int _width;
        int _height;
        bool _active;
        std::string _text;

    public:
        AWidget(void);
        AWidget(
            const Coord &coord,
            int width = 100,
            int height = 100,
            bool active = true,
            std::string _text = ""
        );
        virtual ~AWidget(void);

        virtual void render(SDL_Renderer* renderer) const = 0;

        Coord getCoord(void) const;
        int getWidth(void) const;
        int getHeight(void) const;
        bool isActive(void) const;
        bool isInactive(void) const;
        void (*getAction(void) const)(void) const;
        std::string getText(void) const;

        void setCoord(const Coord &c);
        void setWidth(int w);
        void setHeight(int h);
        void setActive();
        void setInactive();
        void toggleActive(void);
        void setAction(void (*a)(void));
};

#endif
