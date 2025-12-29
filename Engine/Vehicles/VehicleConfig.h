#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>

namespace ote::vehicles {
struct WheelDesc { glm::vec3 position; float radius; float suspensionRest; float suspensionStiffness; float suspensionDamping; };
struct DoorDesc { std::string name; float openTime{2.0f}; };

struct VehicleConfig {
    std::string name;
    float mass = 12000.0f;
    glm::vec3 comOffset{0.0f,-0.5f,0.5f};
    std::vector<WheelDesc> wheels;
    std::vector<DoorDesc> doors;
};

VehicleConfig LoadVehicleConfig(const std::string& path);
}
