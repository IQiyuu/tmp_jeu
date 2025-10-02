#include "AWidget.hpp"

AWidget::AWidget(void) : _x(0), _y(0), _width(100), _height(100), _active(true), _text("") {}
AWidget::AWidget(int x, int y, int width, int height, bool active, std::string text)
    : _x(x), _y(y), _width(width), _height(height), _active(active), _text(text) {}
AWidget::~AWidget(void) {}

int AWidget::getX(void) const { return this->_x; }
int AWidget::getY(void) const { return this->_y; }
int AWidget::getWidth(void) const { return this->_width; }
int AWidget::getHeight(void) const { return this->_height; }
bool AWidget::isActive(void) const { return this->_active; }
std::string AWidget::getText(void) const { return this->_text; }

void AWidget::setX(int x) { this->_x = x; }
void AWidget::setY(int y) { this->_y = y; }
void AWidget::setWidth(int w) { this->_width = w; }
void AWidget::setHeight(int h) { this->_height = h; }
void AWidget::toggleActive(void) { this->_active = !this->_active; }
void AWidget::setActive(void) { this->_active = true; }
void AWidget::setInactive(void) { this->_active = true; }
