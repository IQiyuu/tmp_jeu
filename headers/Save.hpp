#pragma once

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

class Save {
    private:
        std::map<std::string, std::map<std::string, std::string>> _data;
        std::string                        _filename;
    
    public:
        Save(const std::string &f = "assets/save.json");
        ~Save(void);

        void    save(void) const;
        void    load(void);

        void printData() const;
        void printData(const std::string &) const;

        std::string                         getData(const std::string &) const;
        std::map<std::string, std::string>  getDatas(const std::string &) const;
        void                                setData(const std::string &, const std::string &);
};