#include "Text.cpp"

Text::Text(void) {
    // init la font qui se trouve dans assets machins de base dans les files /usr/share/... a changer plus tard
    this_font = TTF_OpenFont("assets/Ubuntu-B.ttf", 24);
    if (!font) {
        std::cerr << "Erreur ouverture font: " << TTF_GetError() << std::endl;
        return 1;
    }
}