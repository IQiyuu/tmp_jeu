#include "Settings.hpp"

Settings::Settings(void):
    _masterVolume(50), _musicVolume(50), _sfxVolume(50), _speaker("default"),
    _windowWidth(1024), _windowHeight(800), _fullscreen(true), _fpsCap(60) {}


Settings::Settings(
    const std::map<std::string, std::string>& m,
    const std::map<std::string, std::string>& b
) {
    this->setSettings(m);
    this->setBindings(b);
}

void Settings::printSettings() const {
    std::cout << "[Settings]" << std::endl;
    std::cout << "  masterVolume : " << _masterVolume << std::endl;
    std::cout << "  musicVolume  : " << _musicVolume << std::endl;
    std::cout << "  sfxVolume    : " << _sfxVolume << std::endl;
    std::cout << "  speaker      : " << _speaker << std::endl;
    std::cout << "  windowWidth  : " << _windowWidth << std::endl;
    std::cout << "  windowHeight : " << _windowHeight << std::endl;
    std::cout << "  fullscreen   : " << (_fullscreen ? "true" : "false") << std::endl;
    std::cout << "  fpsCap       : " << _fpsCap << std::endl;

    std::cout << "[Bindings]" << std::endl;
    for (const auto& [key, val] : _binds) {
        std::cout << "  " << key << " : " << val << std::endl;
    }
}

Settings::~Settings(void) {}

// getters setters
int     Settings::getBind(const std::string &key) const { return this->_binds.at(key); }
void    Settings::setBind(std::string &key, int i) { this->_binds[key] = i; }

int     Settings::getMusicVolume(void) const { return this->_musicVolume; }
void    Settings::setMusicVolume(int i) { this->_musicVolume = i; }

int     Settings::getMasterVolume(void) const { return this->_masterVolume; }
void    Settings::setMasterVolume(int i) { this->_masterVolume = i; }

int     Settings::getSFXVolume(void) const { return this->_sfxVolume; }
void    Settings::setSFXVolume(int i) { this->_sfxVolume = i; }

int     Settings::getWindowHeight(void) const { return this->_windowHeight; }
void    Settings::setWindowHeight(int i) { this->_windowHeight = i; }

int     Settings::getWindowWidth(void) const { return this->_windowWidth; }
void    Settings::setWindowWidth(int i) { this->_windowWidth = i; }

bool    Settings::getFullscreen(void) const { return this->_fullscreen; }
void    Settings::setFullscreen(bool i) { this->_fullscreen = i; }

int     Settings::getFpsCap(void) const { return this->_fpsCap; }
void    Settings::setFpsCap(int i) { this->_fpsCap = i; }

void Settings::setSettings(const std::map<std::string, std::string>& m) {
    auto it = m.find("master_volume");
    if (it != m.end()) this->_masterVolume = std::stoi(it->second);

    it = m.find("music_volume");
    if (it != m.end()) this->_musicVolume = std::stoi(it->second);

    it = m.find("sfx_volume");
    if (it != m.end()) this->_sfxVolume = std::stoi(it->second);

    it = m.find("speaker");
    if (it != m.end()) this->_speaker = it->second;

    it = m.find("window_height");
    if (it != m.end()) this->_windowHeight = std::stoi(it->second);

    it = m.find("window_width");
    if (it != m.end()) this->_windowWidth = std::stoi(it->second);

    it = m.find("fps_cap");
    if (it != m.end()) this->_fpsCap = std::stoi(it->second);

    it = m.find("fullscreen");
    if (it != m.end()) 
        this->_fullscreen = (it->second == "true" || it->second == "1");
}


void    Settings::setBindings(const std::map<std::string, std::string>& b) {
    for (const auto& [key, val] : b) {
        try {
            this->_binds[key] = std::stoi(val);
        } catch (...) {
            std::cerr << "Invalid bind value for key: " << key << std::endl;
        }
    }
}