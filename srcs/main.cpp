#include "Controller.hpp"

int main(int ac, char* av[]) {
    (void)ac;
    (void)av;

    Controller controller;

    SDL_Event event = controller.getEvent(); // référence, pas pointeur
 // ><

    while (controller.getRunning()) {
        Panel *panel = controller.getActivePanel();

        while (SDL_PollEvent(&event)) {
            controller.setEvent(event);
            if (event.type == SDL_QUIT)
                controller.stopRunning();

            int x = event.button.x;
            int y = event.button.y;

            if (panel) {
                std::vector<AClickableWidget*> btns = panel->getActiveWidgets();
                for (auto &btn : btns) {
                    if (btn->isIn(x, y)) {
                        if (event.type == SDL_MOUSEBUTTONDOWN) {
                            if (btn->execute())
                                break ;
                        }
                        else if (event.type == SDL_MOUSEMOTION && (event.motion.state & SDL_BUTTON_LMASK)) {
                            if (btn->execute())
                                break ;
                        }
                    }
                }
            }
        }
        SDL_RenderPresent(controller.getRenderer());
        SDL_Delay(16); // a changer par le fps cap des settings
    }


    return 0;
}
