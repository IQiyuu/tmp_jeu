#include "Menu.hpp"

Menu::Menu(void) {}
Menu::Menu(std::vector<Panel *> p): _panels(p) {}
Menu::Menu(const Menu &m): _panels(m._panels) {}
Menu::~Menu(void) {
    for (auto p : this->_panels)
        delete p;
}

Menu &Menu::operator=(const Menu &m) {
    this->_panels = m._panels;
    return *this;
}

std::vector<Panel *> Menu::getPanels(void) const { return this->_panels; }
void                 Menu::addPanels(Panel * p) {
    this->_panels.push_back(p);
}