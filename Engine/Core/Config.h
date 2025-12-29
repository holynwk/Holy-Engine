#pragma once
#include <string>
#include <unordered_map>

namespace ote::core {
class Config {
public:
    static Config& Instance();
    bool Load(const std::string& path);
    std::string Get(const std::string& key, const std::string& def = "") const;
    double GetFloat(const std::string& key, double def = 0.0) const;
private:
    std::unordered_map<std::string, std::string> values_;
};
}
