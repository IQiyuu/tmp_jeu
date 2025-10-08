#include "Panel.hpp"
 // ><
Panel::Panel(int x, int y, int w, int h): _x(x), _y(y), _w(w), _h(h) {}
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
    for (auto &w : this->_widgets)
        w->setActive();
    this->display(r);
}

void        Panel::disableAll(SDL_Renderer *r) {
    for (auto &w : this->_widgets)
        w->setInactive();
    this->hide(r);
}

bool    Panel::isActive(void) const { return this->_active; }

void    Panel::disable() {
    std::cout << DEBUG << " Enabling Panel" << std::endl;
    this->_active = false;
}
void    Panel::enable() {
    std::cout << DEBUG << " Enabling Panel" << std::endl;
    this->_active = true;
}

void    Panel::display(SDL_Renderer *r) {
    this->hide(r);
    for (auto &w : this->_widgets) {
        if (w->isActive())
            w->render(r);
    }
}

void    Panel::hide(SDL_Renderer *r) {
    SDL_Rect rect = {this->_x, this->_y, this->_w, this->_h};
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    SDL_RenderFillRect(r, &rect);
}

int    Panel::getX(void) const { return this->_x; }
int    Panel::getY(void) const { return this->_y; }
int    Panel::getWidth(void) const { return this->_w; }
int    Panel::getHeight(void) const { return this->_h; }