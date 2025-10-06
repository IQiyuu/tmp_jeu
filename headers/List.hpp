#pragma once

#include "AClickableWidget.hpp"
#include "Text.hpp"
#include <functional>
#include <vector>

class List : public AClickableWidget {
    private:
        Text _text;
        std::vector<Text> _list;
    public:
        List(
            int x = 0,
            int y = 0,
            int width = 100,
            int height = 100,
            const std::function<void(void)>& action = {},
            const std::string& text = ""
        );
        List(const List& other);
        ~List();

        List& operator=(const List& other);

        void render(SDL_Renderer* renderer) const;
        void hide(SDL_Renderer* renderer) const;

};