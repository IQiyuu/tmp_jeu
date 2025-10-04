#include "AClickableWidget.hpp"

AClickableWidget::AClickableWidget(int x, int y, int width, int height, bool active, const std::string& text)
    : AWidget(x, y, width, height, active), _action(nullptr), _text(x, y, text) {}

AClickableWidget::~AClickableWidget(void) {}

bool AClickableWidget::isIn(int x, int y) const {
    return x >= this->_x && x <= this->_x + this->_width &&
           y >= this->_y && y <= this->_y + this->_height;
}

void AClickableWidget::execute(void) {
    if (this->_action) this->_action();
}

void AClickableWidget::setAction(const std::function<void(void)>& action) {
    this->_action = action;
}

void AClickableWidget::setText(const std::string& content) {
    this->_text = Text(this->_x, this->_y, content);
}

Text& AClickableWidget::getText(void) {
    return this->_text;
}

const Text& AClickableWidget::getText(void) const {
    return this->_text;
}