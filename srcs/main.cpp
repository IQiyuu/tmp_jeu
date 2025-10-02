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

    SDL_Renderer* canvas = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!canvas) {
        std::cout << "Erreur SDL_CreateRenderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Button *button = new Button(500,500);
    std::vector<AClickableWidget *> buttons;

    buttons.push_back(button);

    Menu menu = Menu(buttons);

    bool running = true;
    SDL_Event event;
    while (running) {
        SDL_SetRenderDrawColor(canvas, 0, 0, 0, 255);
        SDL_RenderClear(canvas);
        std::vector<AClickableWidget *> actives = menu.getActiveWidgets();
        for (auto &btn : actives) {
            if (btn->isActive())
                btn->render(canvas);
            SDL_RenderPresent(canvas);
        }
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x;
                int y = event.button.y;
                for (auto &btn : actives) {
                    if (btn->isIn(x, y)) {
                            std::cout << "btn cliqued" << std::endl;
                    }
                }
            }
        }
    }
    SDL_DestroyRenderer(canvas);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
