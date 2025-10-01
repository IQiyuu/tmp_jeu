#include "Button.hpp"
#include <SDL2/SDL.h>

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

    Button button;

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
