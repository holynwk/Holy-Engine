#pragma once
#include <glm/glm.hpp>
#include <entt/entt.hpp>

namespace ote::scene {
struct Transform {
    glm::vec3 position{0};
    glm::vec3 rotation{0};
    glm::vec3 scale{1.0f,1.0f,1.0f};
};

class TransformSystem {
public:
    static glm::mat4 Compose(const Transform& t);
};
}
