#include "Panel.hpp"
 // ><
Panel::Panel(void) {}
Panel::Panel(std::vector<AClickableWidget *>w): _widgets(w) {}
Panel::Panel(const Panel &m): _widgets(m._widgets) {}
Panel::~Panel(void) {
    std::cout << DEBUG << " Deleting Panel" << std::endl;
    for (auto w : this->_widgets)
        delete w;
}

Panel    &Panel::operator=(const Panel &m) {
    this->_widgets = m._widgets;
    return *this;
}

std::vector<AClickableWidget *>  Panel::getWidgets(void) const { return this->_widgets; }
std::vector<AClickableWidget *>  Panel::getActiveWidgets(void) const {
    std::vector<AClickableWidget *> ret;
    for (auto &w : this->_widgets) {
        if (w->isActive())
            ret.push_back(w);
    }
    return ret;
}
std::vector<AClickableWidget *>  Panel::getInactiveWidgets(void) const {
    std::vector<AClickableWidget *> ret;
    for (auto &w : this->_widgets) {
        if (!w->isActive())
            ret.push_back(w);
    }
    return ret;
}

std::string Panel::getName(void) const { return this->_name; }

void        Panel::setName(std::string name) { this->_name = name; }

void        Panel::addWidgets(std::vector<AClickableWidget *> ws) { 
    for (auto &w : ws)
        this->_widgets.push_back(w);
}
void        Panel::addWidget(AClickableWidget *w) { this->_widgets.push_back(w); }

void        Panel::enableAll(SDL_Renderer *r) {
    for (auto &w : this->_widgets) {
        w->setActive();
        w->render(r);
    }
}

void        Panel::disableAll(SDL_Renderer *r) {
    for (auto &w : this->_widgets) {
        w->hide(r);
        w->setInactive();
    }
}

bool    Panel::isActive(void) const { return this->_active; }

void    Panel::disable(SDL_Renderer *r) {
    std::cout << DEBUG << " Enabling Panel" << std::endl;
    this->_active = false;
    this->disableAll(r);
}
void    Panel::enable(SDL_Renderer *r) {
    std::cout << DEBUG << " Enabling Panel" << std::endl;
    this->_active = true;
    this->enableAll(r);
}
