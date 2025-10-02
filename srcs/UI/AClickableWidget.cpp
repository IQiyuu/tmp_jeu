#include "AClickableWidget.hpp"

AClickableWidget::AClickableWidget(const Coord& coord, int width, int height, bool active)
    : AWidget(coord, width, height, active), _action(nullptr) {}

AClickableWidget::~AClickableWidget(void) {}

bool AClickableWidget::isIn(int x, int y) const {
    return x >= _coord.getX() && x <= _coord.getX() + _width &&
           y >= _coord.getY() && y <= _coord.getY() + _height;
}

void AClickableWidget::execute(void) {
    if (_action) _action();
}

void AClickableWidget::setAction(const std::function<void()>& action) {
    _action = action;
}