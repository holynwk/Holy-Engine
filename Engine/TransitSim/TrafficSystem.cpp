#include "TrafficSystem.h"

namespace ote::transit {
void TrafficSystem::Update(float dt) {
    for (auto& a : agents_) {
        auto dir = a.target - a.position;
        float len = glm::length(dir);
        if (len > 0.1f) {
            a.position += (dir/len) * a.speed * dt;
        }
    }
}
}
