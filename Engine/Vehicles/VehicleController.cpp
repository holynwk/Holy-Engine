#include "VehicleController.h"
#include "../Core/Logger.h"

namespace ote::vehicles {
VehicleController::VehicleController(const VehicleConfig& cfg, ote::physics::RigidBody* body) : cfg_(cfg), body_(body) {
    for (const auto& w : cfg_.wheels) {
        wheels_.push_back({w.position, 0.0f});
    }
}

void VehicleController::SetInputs(float throttle, float brake, float steer, bool parking, bool ignition) {
    throttle_ = throttle; brake_ = brake; steer_ = steer; parking_ = parking; ignition_ = ignition;
}

void VehicleController::Update(float dt, float lodFactor) {
    lod_ = lodFactor;
    float consumption = brake_ * 0.5f;
    pneumatics_.Update(dt, consumption);
    brakes_.SetInputs(brake_, parking_);
    float air = pneumatics_.Pressure();
    float brakeForce = brakes_.BrakeForce(air);
    glm::vec3 forward = {0,0,1};
    body_->velocity += forward * (throttle_ * 5.0f - brakeForce * 0.0001f) * dt;
    body_->velocity *= 0.999f;
    body_->position += body_->velocity * dt;
    body_->position.y = 0.0f; // keep on ground
}
}
