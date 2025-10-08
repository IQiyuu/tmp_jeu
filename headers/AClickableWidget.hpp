#pragma once

#include "AWidget.hpp"
#include <functional>

class AClickableWidget : public AWidget {
    protected:
        std::function<void(void)> _action;
        Text _text;

    public:
        AClickableWidget(
            int x = 0,
            int y = 0,
            int width = 100,
            int height = 100,
            bool active = true,
            const std::string& text = ""
        );
        virtual ~AClickableWidget(void);

        virtual bool isIn(int x, int y) const;
        virtual bool execute(void);

        void setAction(const std::function<void(void)>& action);
        void setText(const std::string& content);
        Text& getText(void);
        const Text& getText(void) const;


        virtual void hide(SDL_Renderer* renderer) const = 0;
        virtual void render(SDL_Renderer* renderer) const = 0;
};