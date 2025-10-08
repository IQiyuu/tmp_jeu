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

    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);
    SDL_RenderClear(this->_renderer);

    // menus/widgets
    this->createMainMenu();
    this->createSettingsMenu();
}

Controller::~Controller(void) {
    std::cout << DEBUG << " Deleting Controller" << std::endl;
    delete this->_main_menu;
    delete this->_settings_menu;

    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);

    TTF_Quit();
    SDL_Quit();
}

void        Controller::createSettingsMenu(void) {
    this->_settings_menu = new Menu();
    Panel *p = new Panel();

    Button      *cross = new Button(5, 5, 25, 25, [](){}, "X");
    Slider      *slider  = new Slider(WIDTH/2 - 75, 50, 150, 25, [](){}, "Volume:");
    Box         *box = new Box(WIDTH/2 - 12.5, 100, 25, 25, [](){}, "Fullscreen:");
    DropDown    *dd = new DropDown(WIDTH/2 - 75, 150, 150, 50, [](){}, "Resolution:");

    std::vector<AClickableWidget *> btns = { dd, cross, slider, box };
    p->addWidgets(btns);
    this->_settings_menu->addPanel(p);

    cross->setAction([this](){
        std::cout << "Return to main menu" << std::endl;
        this->_settings_menu->disable(this->_renderer);
        this->_main_menu->enable(this->_renderer);
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
        box->render(this->_renderer);
    });
    dd->setAction([this, dd, p](){
        std::cout << "dropdown " << dd->getDropDown() << std::endl;
        dd->setDropDown(!dd->getDropDown());
        if (dd->getDropDown())
            dd->render(this->_renderer);
        else
            p->enableAll(this->_renderer);
    });

    p->enable();
    std::cout << p->getActiveWidgets().size() << std::endl;
}

void        Controller::createMainMenu(void) {
    this->_main_menu = new Menu();
    Panel *p = new Panel();

    Button *start_b = new Button(WIDTH/2 - 75, 50, 150, 50, [](){}, "Start");
    Button *sett_b  = new Button(WIDTH/2 - 75, 150, 150, 50, [](){}, "Settings");
    Button *leave_b = new Button(WIDTH/2 - 75, 250, 150, 50, [](){}, "Leave");
    

    std::vector<AClickableWidget *> btns = { start_b, sett_b, leave_b };
    p->addWidgets(btns);
    this->_main_menu->addPanel(p);

    // actions
    start_b->setAction([p, this]() {
        std::cout << "starting the game" << std::endl;
        p->disable();
        p->hide(this->_renderer);
    });

    sett_b->setAction([p, this]() {
        std::cout << "settings the game" << std::endl;
        this->_main_menu->disable(this->_renderer);
        this->_settings_menu->enable(this->_renderer);
    });

    leave_b->setAction([this]() {
        std::cout << "leave the game" << std::endl;
        this->stopRunning();
    });
    p->enable();
    p->enableAll(this->_renderer);
}

Menu         *Controller::getMainMenu(void) const { return this->_main_menu; }
SDL_Renderer *Controller::getRenderer(void) const { return this->_renderer; }
SDL_Event    &Controller::getEvent(void) { return this->_event; }
bool         Controller::getRunning(void) const { return this->_running; }
Panel       *Controller::getActivePanel(void) const {
    if (this->_main_menu->isActive()) {
        return this->_main_menu->getActivePanel();
    }
        if (this->_settings_menu->isActive())
     {  
        return this->_settings_menu->getActivePanel();
     }return nullptr;
}

void         Controller::setEvent(SDL_Event &event) { this->_event = event; }
void         Controller::stopRunning(void) { this->_running = false; }