#pragma once

#include "AClickableWidget.hpp"
#include "Text.hpp"
#include <functional>
#include <vector>

class DropDown : public AClickableWidget {
    private:
        Text _text;
        std::vector<Text *> _list;
        bool              _isDropDown;

    public:
        DropDown(
            int x = 0,
            int y = 0,
            int width = 100,
            int height = 100,
            const std::function<void(void)>& action = {},
            const std::string& text = ""
        );
        DropDown(const DropDown& other);
        ~DropDown();

        DropDown& operator=(const DropDown& other);

        bool    execute(void);

        void    setDropDown(bool);
        bool    getDropDown(void) const;

        void render(SDL_Renderer* renderer) const;
        void hide(SDL_Renderer* renderer) const;

};