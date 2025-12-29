#pragma once
#include <glm/glm.hpp>

namespace ote::vehicles {
class Articulation {
public:
    float angle = 0.0f;
    void Update(float dt, float torque) { angle += torque * dt; if (angle > maxAngle_) angle = maxAngle_; if (angle < -maxAngle_) angle = -maxAngle_; }
    float MaxAngle() const { return maxAngle_; }
private:
    float maxAngle_ = 0.6f; // radians
};
}
