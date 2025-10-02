#include "Menu.hpp"

Menu::Menu(void) {}
Menu::Menu(std::vector<AClickableWidget *>w): _widgets(w) {}
Menu::Menu(const Menu &m): _widgets(m._widgets) {}
Menu::~Menu(void) {
    for (auto w : this->_widgets)
        delete w;
}

Menu    &Menu::operator=(const Menu &m) {
    this->_widgets = m._widgets;
    return *this;
}

std::vector<AClickableWidget *>  Menu::getWidgets(void) const { return this->_widgets; }
std::vector<AClickableWidget *>  Menu::getActiveWidgets(void) const {
    std::vector<AClickableWidget *> ret;
    for (auto w : this->_widgets) {
        if (w->isActive())
            ret.push_back(w);
    }
    return ret;
}
std::vector<AClickableWidget *>  Menu::getInactiveWidgets(void) const {
    std::vector<AClickableWidget *> ret;
    for (auto w : this->_widgets) {
        if (!w->isActive())
            ret.push_back(w);
    }
    return ret;
}
