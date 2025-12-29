#include "Serialization.h"
#include <fstream>

namespace ote::scene {
bool Serialization::Save(const std::string& path, entt::registry& /*registry*/) {
    std::ofstream f(path);
    if (!f.is_open()) return false;
    f << "{}";
    return true;
}

bool Serialization::Load(const std::string& path, entt::registry& /*registry*/) {
    std::ifstream f(path);
    return f.good();
}
}
