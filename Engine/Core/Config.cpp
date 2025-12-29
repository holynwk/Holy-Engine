#include "Config.h"
#include <fstream>
#include <sstream>

namespace ote::core {
Config& Config::Instance() {
    static Config c;
    return c;
}

bool Config::Load(const std::string& path) {
    std::ifstream f(path);
    if (!f.is_open()) return false;
    std::string line;
    while (std::getline(f, line)) {
        if (line.empty() || line[0] == '#') continue;
        auto pos = line.find('=');
        if (pos == std::string::npos) continue;
        std::string key = line.substr(0, pos);
        std::string val = line.substr(pos + 1);
        values_[key] = val;
    }
    return true;
}

std::string Config::Get(const std::string& key, const std::string& def) const {
    auto it = values_.find(key);
    if (it == values_.end()) return def;
    return it->second;
}

double Config::GetFloat(const std::string& key, double def) const {
    auto str = Get(key, "");
    if (str.empty()) return def;
    try { return std::stod(str); } catch(...) { return def; }
}
}
