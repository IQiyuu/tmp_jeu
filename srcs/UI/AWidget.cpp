#include "AWidget.hpp"

AWidget::AWidget(void) : _coord(0,0), _width(100), _height(100), _active(true) {}
AWidget::AWidget(const Coord &coord, int width, int height, bool active)
    : _coord(coord), _width(width), _height(height), _active(active) {}
AWidget::~AWidget(void) {}

Coord AWidget::getCoord(void) const { return _coord; }
int AWidget::getWidth(void) const { return _width; }
int AWidget::getHeight(void) const { return _height; }
bool AWidget::isActive(void) const { return _active; }

void AWidget::setCoord(const Coord &c) { _coord = c; }
void AWidget::setWidth(int w) { _width = w; }
void AWidget::setHeight(int h) { _height = h; }
void AWidget::setActive(bool a) { _active = a; }
void AWidget::toggleActive(void) { _active = !_active; }
