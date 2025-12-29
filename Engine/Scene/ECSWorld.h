#pragma once
#include <entt/entt.hpp>

namespace ote::scene {
class ECSWorld {
public:
    entt::registry& Registry() { return registry_; }
private:
    entt::registry registry_;
};
}
