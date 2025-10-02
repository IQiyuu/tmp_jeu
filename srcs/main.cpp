#include "Controller.hpp"

int main(int ac, char* av[]) {
    (void)ac;
    (void)av;

    // Menu menu;
    // Panel *p = new Panel();
    
    // menu.addPanel(p);

    // Button *btn = new Button(WIDTH/2-50, HEIGHT/2-100, 200, 100, &nothing, "Start");

    // p->addWidget(btn);

    // TTF_Font* font = TTF_OpenFont("assets/Ubuntu-B.ttf", 24);
    // if (!font) {
    //     std::cerr << "Erreur ouverture font: " << TTF_GetError() << std::endl;
    //     return 1;
    // }

    // SDL_Surface* surface = TTF_RenderText_Solid(font, "Start", SDL_Color{255,255,255,255});
    // SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // SDL_Rect dst;
    // dst.x = btn->getX(); // position du bouton
    // dst.y = btn->getY();
    // dst.w = surface->w;  // largeur exacte du texte
    // dst.h = surface->h;  // hauteur exacte du texte

    
    // SDL_RenderCopy(renderer, texture, NULL, &dst);

    Controller controller;

    // SDL_RenderCopy(renderer, texture, NULL, &dst);

    bool running = true;
    SDL_Event event;
    while (running) {
        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // SDL_RenderClear(renderer);

        Panel *panel = controller.getMainMenu()->getActivePanel();
        std::vector<AClickableWidget*> btns = panel->getActiveWidgets();

        // for (auto& btn : btns) {
        //     if (btn->isActive())
        //         btn->render(renderer);
        // }
        // SDL_RenderCopy(renderer, texture, NULL, &dst);
        // SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x;
                int y = event.button.y;

                for (auto &btn : btns) {
                    if (btn->isIn(x, y)) {
                        std::cout << "btn clicked" << std::endl;
                        btn->execute();
                    }
                }
            }
        }
    }

    // SDL_FreeSurface(surface);
    // SDL_DestroyTexture(texture); // libérer la texture après rendu
    // TTF_CloseFont(font);
    // TTF_Quit();
    return 0;
}
