#include "Controller.hpp"

int main(int ac, char* av[]) {
    (void)ac;
    (void)av;

    Controller controller;

    bool running = true;
    SDL_Event event;
    while (running) {
        Panel *panel = controller.getMainMenu()->getActivePanel();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x;
                int y = event.button.y;
                if (panel) {
                    std::vector<AClickableWidget*> btns = panel->getActiveWidgets();
                    for (auto &btn : btns) {
                        if (btn->isIn(x, y)) {
                            std::cout << "btn clicked" << std::endl;
                            btn->execute();
                        }
                    }
                }
            }
        }
        SDL_RenderPresent(controller.getRenderer());
    }

    // SDL_FreeSurface(surface);
    // SDL_DestroyTexture(texture); // libérer la texture après rendu
    // TTF_CloseFont(font);
    // TTF_Quit();
    return 0;
}
