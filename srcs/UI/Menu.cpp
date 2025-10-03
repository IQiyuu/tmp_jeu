#include "Menu.hpp"

Menu::Menu(void) {}
Menu::Menu(std::vector<Panel *> p): _panels(p) {}
Menu::Menu(const Menu &m): _panels(m._panels) {}
Menu::~Menu(void) {
    std::cout << DEBUG << " Deleting Menu" << std::endl;
    for (auto p : this->_panels)
        delete p;
}

Menu &Menu::operator=(const Menu &m) {
    this->_panels = m._panels;
    return *this;
}

std::vector<Panel *> Menu::getPanels(void) const { return this->_panels; }
Panel               *Menu::getActivePanel(void) const {
    for (auto &p : this->_panels)
        if (p->isActive())
            return p;
    return nullptr;
}
void                 Menu::addPanel(Panel * p) { this->_panels.push_back(p); }

void                 Menu::createPanel(void) {
    Panel *p = new Panel();
    this->_panels.push_back(p);
}