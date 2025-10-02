#ifndef ACLICKABLEWIDGET_HPP
#define ACLICKABLEWIDGET_HPP

#include "AWidget.hpp"
#include <functional>

class AClickableWidget : public AWidget {
    protected:
        std::function<void()> _action;

    public:
        AClickableWidget(
            int x = 0,
            int y = 0,
            int width = 100,
            int height = 100,
            bool active = true,
            std::string text = ""
        );
        virtual ~AClickableWidget(void);

        virtual bool isIn(int x, int y) const;
        virtual void execute(void);
        void setAction(const std::function<void()>& action);
};

#endif
