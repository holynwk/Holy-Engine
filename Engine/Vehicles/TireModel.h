#pragma once
#include <glm/glm.hpp>

namespace ote::vehicles {
struct TireForces { glm::vec3 force{0}; };
inline TireForces ComputeTire(const glm::vec3& velocity, float normalForce, float steer, float throttle, float brake) {
    TireForces tf; float grip = normalForce * 0.9f; float fx = (throttle - brake) * grip; tf.force = {fx, 0.0f, -steer * grip * 0.5f}; return tf;
}
}
