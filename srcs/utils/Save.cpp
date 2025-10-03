#include "Save.hpp"

Save::Save(const std::string &f): _filename(f) {
    load();    
}

Save::~Save(void) {
    //save();
}

void Save::printData() const {
    for (const auto &categoryPair : this->_data) {
        std::cout << "[" << categoryPair.first << "]" << std::endl;
        for (const auto &kv : categoryPair.second) {
            std::cout << "  " << kv.first << " : " << kv.second << std::endl;
        }
    }
}

void Save::printData(const std::string &s) const {
    auto it = this->_data.find(s);
    if (it == this->_data.end()) {
        std::cout << "Category \"" << s << "\" not found." << std::endl;
        return;
    }

    std::cout << "[" << it->first << "]" << std::endl;
    for (const auto &kv : it->second) {
        std::cout << "  " << kv.first << " : " << kv.second << std::endl;
    }
}

void    Save::save(void) const {
    return ;
}

std::map<std::string, std::string> Save::getDatas(const std::string &s) const {
    return this->_data.at(s);
}

void Save::load(void) {
    std::ifstream ifs(this->_filename);
    if (!ifs) {
        std::cerr << "Save file not found, skipping load: " << this->_filename << std::endl;
        return;
    }

    std::string line, currentCategory;

    while (std::getline(ifs, line)) {
        // trim espaces/tabs
        line.erase(0, line.find_first_not_of(" \t\n\r"));
        line.erase(line.find_last_not_of(" \t\n\r") + 1);

        if (line.empty() || line == "{" || line == "}")
            continue;

        // Début d'une catégorie
        if (line.find('{') != std::string::npos) {
            size_t start = line.find('"') + 1;
            size_t end   = line.find('"', start);
            if (start != std::string::npos && end != std::string::npos)
                currentCategory = line.substr(start, end - start);
            continue;
        }

        // Ligne clé-valeur
        size_t keyStart = line.find('"');
        if (keyStart == std::string::npos) continue;

        size_t keyEnd = line.find('"', keyStart + 1);
        if (keyEnd == std::string::npos) continue;

        std::string key = line.substr(keyStart + 1, keyEnd - keyStart - 1);

        size_t colon = line.find(':', keyEnd);
        if (colon == std::string::npos) continue;

        std::string val = line.substr(colon + 1);
        // trim espaces et virgule
        val.erase(0, val.find_first_not_of(" \t\n\r"));
        val.erase(val.find_last_not_of(" \t\n\r,") + 1);

        // enlever guillemets si présents
        if (!val.empty() && val.front() == '"') val.erase(0, 1);
        if (!val.empty() && val.back() == '"') val.pop_back();

        // stocker la valeur
        if (!currentCategory.empty())
            this->_data[currentCategory][key] = val;
    }
}
