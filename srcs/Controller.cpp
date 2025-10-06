#include "Controller.hpp"

Controller::Controller(void) {
    this->_running = true;
    // Charger settings/bindings
    this->settings.setSettings(this->save.getDatas("settings"));
    this->settings.setBindings(this->save.getDatas("bindings"));

    this->settings.printSettings();

    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("SDL init failed");

    this->_window = SDL_CreateWindow(
        "jeu_tmp",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!this->_window)
        throw std::runtime_error("Window creation failed");

    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->_renderer) {
        SDL_DestroyWindow(this->_window);
        SDL_Quit();
        throw std::runtime_error("Renderer creation failed");
    }

    if (TTF_Init() == -1) {
        SDL_DestroyRenderer(this->_renderer);
        SDL_DestroyWindow(this->_window);
        SDL_Quit();
        throw std::runtime_error("TTF init creation failed");
    }

    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->_renderer);

    // menus/widgets
    this->_main_menu = new Menu();
    Panel *p = new Panel();

    Button *start_b = new Button(WIDTH/2 - 75, 50, 150, 50, [](){}, "Start");
    Button *sett_b  = new Button(WIDTH/2 - 75, 150, 150, 50, [](){}, "Settings");
    Button *leave_b = new Button(WIDTH/2 - 75, 250, 150, 50, [](){}, "Leave");
    Slider *slider  = new Slider(WIDTH/2 - 75, 350, 150, 25, [](){}, "Volume");
    Box     *box = new Box(WIDTH/2, 450, 25, 25, [](){}, "Fullscreen");

    std::vector<AClickableWidget *> btns = {start_b, sett_b, leave_b, slider, box};
    p->addWidgets(btns);
    this->_main_menu->addPanel(p);

    // actions
    start_b->setAction([p, this]() {
        std::cout << "starting the game" << std::endl;
        p->disable(this->_renderer);
    });

    sett_b->setAction([p, this]() {
        std::cout << "settings the game" << std::endl;
        p->disable(this->_renderer);
    });

    leave_b->setAction([this]() {
        std::cout << "leave the game" << std::endl;
        this->_running = false;
    });

    slider->setAction([this, slider]() {
        SDL_Event &e = this->getEvent();
        std::cout << "sliding the game"  << e.type << std::endl;
        if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEMOTION) {
            int mx = e.button.x;
            int my = e.button.y;
            std::cout << "(" << mx << "," << my << ") (" << 
                        slider->getX() << "," << slider->getY() << ") (" <<
                        slider->getX() + slider->getWidth() << "," << slider->getY() + slider->getHeight() << ")"  << std::endl;


            if (mx >= slider->getX() && mx <= slider->getX() + slider->getWidth() &&
                my >= slider->getY() && my <= slider->getY() + slider->getHeight()) {

                int v = (mx - slider->getX()) * 100 / slider->getWidth();
                v = std::clamp(v, 0, 100);

                slider->setValue(std::to_string(v));
                this->settings.setMasterVolume(v);
                slider->render(this->_renderer);
            }
        }
    });
    box->setAction([this, box](){
        std::cout << "checking box" << std::endl;
        box->setChecked(!box->getCheck());
        std::cout << box->getCheck() << std::endl;
        box->render(this->_renderer);
    });

    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->_renderer);

    p->enableAll(this->_renderer);
}

Controller::~Controller(void) {
    std::cout << DEBUG << " Deleting Controller" << std::endl;
    delete this->_main_menu;

    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);

    TTF_Quit();
    SDL_Quit();
}

Menu         *Controller::getMainMenu(void) const { return this->_main_menu; }
SDL_Renderer *Controller::getRenderer(void) const { return this->_renderer; }
SDL_Event    &Controller::getEvent(void) { return this->_event; }
bool         Controller::getRunning(void) const { return this->_running; }

void         Controller::setEvent(SDL_Event &event) { this->_event = event; }
void         Controller::stopRunning(void) { this->_running = false; }