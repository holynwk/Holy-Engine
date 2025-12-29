#pragma once
#include <glm/glm.hpp>
#include "../Physics/Queries.h"

namespace ote::vehicles {
struct WheelContact {
    glm::vec3 contactPoint{0};
    glm::vec3 normal{0,1,0};
    float compression = 0.0f;
    bool grounded = false;
};
inline WheelContact ComputeContact(const glm::vec3& origin, float restLength) {
    auto hit = ote::physics::Queries::RaycastGround(origin, restLength * 2.0f);
    WheelContact wc; wc.grounded = hit.hit; wc.contactPoint = hit.point; wc.normal = hit.normal; wc.compression = restLength - hit.distance; return wc;
}
}
