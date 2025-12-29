#pragma once
#include <string>
#include <entt/entt.hpp>

namespace ote::scene {
class Serialization {
public:
    static bool Save(const std::string& path, entt::registry& registry);
    static bool Load(const std::string& path, entt::registry& registry);
};
}
