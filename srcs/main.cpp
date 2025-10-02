#include "Menu.hpp"
#include "Button.hpp"

const int WIDTH = 1024;
const int HEIGHT = 800;

int main(int ac, char* av[]) {
    (void)ac;
    (void)av;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur d'initialisation SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Erreur creation fenetre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erreur SDL_CreateRenderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Menu menu;
    Panel *p = new Panel();
    
    menu.addPanel(p);

    Button *btn = new Button();

    p->addWidget(btn);

    bool running = true;
    SDL_Event event;
    while (running) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        Panel& panel = menu.getActivePanel();
        std::vector<AClickableWidget*> btns = panel.getActiveWidgets();

        for (auto& btn : btns) {
            if (btn->isActive())
                btn->render(renderer);
        }

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x;
                int y = event.button.y;

                for (auto& btn : btns) {
                    if (btn->isIn(x, y)) {
                        std::cout << "btn clicked" << std::endl;
                        // btn->execute();
                    }
                }
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
