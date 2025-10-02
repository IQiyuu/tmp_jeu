#ifndef Panel_HPP
#define Panel_HPP

#include "AClickableWidget.hpp"
#include <vector>

class Panel {
    private:
        std::vector<AClickableWidget *> _widgets;
        std::string                     _name;
        bool                            _active;
    
    public:
        Panel(void);
        Panel(std::vector<AClickableWidget *>);
        Panel(const Panel &);
        ~Panel(void);

        Panel &operator=(const Panel &);

        std::string                      getName(void) const;
        std::vector<AClickableWidget *>  getWidgets(void) const;
        std::vector<AClickableWidget *>  getActiveWidgets(void) const;
        std::vector<AClickableWidget *>  getInactiveWidgets(void) const;
        bool                             isActive(void) const;

        void                             disable(void);
        void                             enable(void);
        void                             setName(std::string);

        void                    addWidget(AClickableWidget *);
        void                    enableAll(void);
        void                    disableAll(void);

};

#endif