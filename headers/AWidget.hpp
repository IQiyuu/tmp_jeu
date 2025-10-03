#pragma once

#include "IWidget.hpp"
#include <SDL2/SDL.h>

class AWidget : public IWidget {
    protected:
        int _x;
        int _y;
        int _width;
        int _height;
        bool _active;
        Text _text;

    public:
        AWidget(void);
        AWidget(
            int x,
            int y,
            int width = 100,
            int height = 100,
            bool active = true,
            const std::string& text = ""
        );
        virtual ~AWidget(void);

        virtual void render(SDL_Renderer* renderer) const = 0;

        int getX(void) const;
        int getY(void) const;
        int getWidth(void) const;
        int getHeight(void) const;
        bool isActive(void) const;
        bool isInactive(void) const;

        Text& getText(void);
        const Text& getText(void) const;

        void setX(int);
        void setY(int);
        void setWidth(int);
        void setHeight(int);
        void setActive(void);
        void setInactive(void);
        void toggleActive(void);
        void setText(const std::string& content);
};
