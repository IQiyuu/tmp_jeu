#ifndef AWIDGET_HPP
#define AWIDGET_HPP

#include "IWidget.hpp"
#include <SDL2/SDL.h>

class AWidget: public IWidget {
    protected:
        int _x;
        int _y;
        int _width;
        int _height;
        bool _active;
        std::string _text;

    public:
        AWidget(void);
        AWidget(
            int x = 0,
            int y = 0,
            int width = 100,
            int height = 100,
            bool active = true,
            std::string _text = ""
        );
        virtual ~AWidget(void);

        virtual void render(SDL_Renderer* renderer) const = 0;

        int getX(void) const;
        int getY(void) const;
        int getWidth(void) const;
        int getHeight(void) const;
        bool isActive(void) const;
        bool isInactive(void) const;
        void (*getAction(void) const)(void) const;
        std::string getText(void) const;

        void setX(int);
        void setY(int);
        void setWidth(int);
        void setHeight(int);
        void setActive();
        void setInactive();
        void toggleActive(void);
        void setAction(void (*a)(void));
};

#endif
