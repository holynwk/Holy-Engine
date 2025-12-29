#pragma once
#include <glm/glm.hpp>
#include "WheelContact.h"

namespace ote::vehicles {
struct SuspensionForce {
    glm::vec3 force{0};
};
inline SuspensionForce ComputeSuspension(const WheelContact& contact, float stiffness, float damping, float compressionVelocity) {
    SuspensionForce f; if (!contact.grounded) return f; float spring = contact.compression * stiffness; float damp = compressionVelocity * damping; f.force = contact.normal * (spring - damp); return f;
}
}
