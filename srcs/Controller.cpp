#include "Controller.hpp"

Controller::Controller(void) {
    // init de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("SDL init failed");

    // initialise la fenetre
    this->_window = SDL_CreateWindow(
        "jeu_tmp",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!this->_window)
        throw std::runtime_error("Window creation failed");

    // initialise le renderer
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->_renderer) {
        SDL_DestroyWindow(this->_window);
        SDL_Quit();
        throw std::runtime_error("Renderer creation failed");
    }

    // init TTF
    if (TTF_Init() == -1) {
        SDL_DestroyRenderer(this->_renderer);
        SDL_DestroyWindow(this->_window);
        SDL_Quit();
        throw std::runtime_error("TTF init creation failed");
    }

    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->_renderer);

    // creation du main menu
    this->_main_menu = new Menu();
    Panel *p = new Panel();
    Button *start_b = new Button(WIDTH/2 - 150/2, 50, 150, 50, [](){}, "Start");
    Button *sett_b = new Button(WIDTH/2-150/2, 150, 150, 50, [](){}, "Settings");
    Button *leave_b = new Button(WIDTH/2-150/2, 250, 150, 50, [](){}, "Leave");

    std::vector<AClickableWidget *> btns = {start_b,sett_b,leave_b};
    p->addWidgets(btns);
    this->_main_menu->addPanel(p);
    start_b->render(this->_renderer);
    sett_b->render(this->_renderer);
    leave_b->render(this->_renderer);
    SDL_RenderPresent(this->_renderer);
}

Controller::~Controller(void) {
    delete this->_main_menu;
    SDL_DestroyTexture(this->_texture);
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}