#include "AWidget.hpp"

AWidget::AWidget(void) : _coord(0,0), _width(100), _height(100), _active(true), _text("") {}
AWidget::AWidget(const Coord &coord, int width, int height, bool active, std::string text)
    : _coord(coord), _width(width), _height(height), _active(active), _text(text) {}
AWidget::~AWidget(void) {}

Coord AWidget::getCoord(void) const { return this->_coord; }
int AWidget::getWidth(void) const { return this->_width; }
int AWidget::getHeight(void) const { return this->_height; }
bool AWidget::isActive(void) const { return this->_active; }
std::string AWidget::getText(void) const { return this->_text; }

void AWidget::setCoord(const Coord &c) { this->_coord = c; }
void AWidget::setWidth(int w) { this->_width = w; }
void AWidget::setHeight(int h) { this->_height = h; }
void AWidget::toggleActive(void) { this->_active = !this->_active; }
void AWidget::setActive(void) { this->_active = true; }
void AWidget::setInactive(void) { this->_active = true; }
