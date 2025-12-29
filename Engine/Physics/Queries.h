#pragma once
#include <glm/glm.hpp>

namespace ote::physics {
struct RaycastHit { bool hit=false; glm::vec3 point{0}; glm::vec3 normal{0,1,0}; float distance=0; };
class Queries {
public:
    static RaycastHit RaycastGround(const glm::vec3& origin, float maxDist) {
        RaycastHit h; h.hit = true; h.distance = origin.y; h.point = origin - glm::vec3(0,origin.y,0); return h;
    }
};
}
