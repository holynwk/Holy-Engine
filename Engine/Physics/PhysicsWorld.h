#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "../Core/Profiler.h"

namespace ote::physics {
struct RigidBody {
    glm::vec3 position{0};
    glm::vec3 velocity{0};
    float mass = 1000.0f;
};

class PhysicsWorld {
public:
    void Step(float dt);
    RigidBody* CreateBody();
    const std::vector<RigidBody>& Bodies() const { return bodies_; }
private:
    std::vector<RigidBody> bodies_;
};
}
