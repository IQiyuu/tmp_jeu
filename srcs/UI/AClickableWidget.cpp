#include "AClickableWidget.hpp"

AClickableWidget::AClickableWidget(int x, int y, int width, int height, bool active, std::string text)
    : AWidget(x, y, width, height, active, text), _action(nullptr) {}

AClickableWidget::~AClickableWidget(void) {}

bool AClickableWidget::isIn(int x, int y) const {
    return x >= this->_x && x <= this->_x + this->_width &&
           y >= this->_y && y <= this->_y + this->_height;
}

void AClickableWidget::execute(void) {
    if (this->_action) this->_action();
}

void AClickableWidget::setAction(const std::function<void()>& action) {
   this->_action = action;
}