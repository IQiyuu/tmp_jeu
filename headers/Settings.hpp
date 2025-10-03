#pragma once

#include "Save.hpp"

class Settings {
    private:
        // son
        int         _masterVolume;
        int         _musicVolume;
        int         _sfxVolume;
        std::string _speaker;

        // graphismes
        int     _windowWidth;
        int     _windowHeight;
        bool    _fullscreen;
        int     _fpsCap;

        // inputs
        std::map<std::string, int>  _binds;

    public:
        Settings(void);
        Settings(const std::map<std::string, std::string> &,
                 const std::map<std::string, std::string> &);
        ~Settings(void);

        // setters volume
        void    setMasterVolume(int);
        void    setMusicVolume(int);
        void    setSFXVolume(int);
        void    setSpeaker(std::string);
        // setters window
        void    setWindowWidth(int);
        void    setWindowHeight(int);
        void    setFpsCap(int);
        void    setFullscreen(bool);
        // setters binding
        void    setBind(std::string &, int);

        // getters volume
        int         getMasterVolume(void) const;
        int         getMusicVolume(void) const;
        int         getSFXVolume(void) const;
        std::string getSpeaker(void) const;
        // getters window
        int         getWindowWidth(void) const;
        int         getWindowHeight(void) const;
        int         getFpsCap(void) const;
        bool        getFullscreen(void) const;
        // getters binding
        int         getBind(const std::string &) const;

        void        setSettings(const std::map<std::string, std::string>& m);
        void        setBindings(const std::map<std::string, std::string>& m);
        
        void        printSettings() const;

};
