#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include "VehicleConfig.h"
#include "BrakeSystem.h"
#include "Pneumatics.h"
#include "ABS_ASR.h"
#include "Articulation.h"
#include "../Physics/PhysicsWorld.h"
#include "Suspension.h"
#include "TireModel.h"

namespace ote::vehicles {
struct WheelState {
    glm::vec3 position{0};
    float steer = 0.0f;
};

class VehicleController {
public:
    VehicleController(const VehicleConfig& cfg, ote::physics::RigidBody* body);
    void SetInputs(float throttle, float brake, float steer, bool parking, bool ignition);
    void Update(float dt, float lodFactor);
    const VehicleConfig& Config() const { return cfg_; }
    const std::vector<WheelState>& Wheels() const { return wheels_; }
    float SpeedKmh() const { return glm::length(body_->velocity) * 3.6f; }
    float AirPressure() const { return pneumatics_.Pressure(); }
    float LOD() const { return lod_; }
private:
    VehicleConfig cfg_;
    ote::physics::RigidBody* body_;
    std::vector<WheelState> wheels_;
    BrakeSystem brakes_;
    Pneumatics pneumatics_;
    ABS_ASR abs_;
    Articulation articulation_;
    float throttle_ = 0.0f;
    float brake_ = 0.0f;
    float steer_ = 0.0f;
    bool parking_ = false;
    bool ignition_ = false;
    float lod_ = 0;
};
}
