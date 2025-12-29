#include "VehicleConfig.h"
#include <fstream>
#include <sstream>

namespace ote::vehicles {
VehicleConfig LoadVehicleConfig(const std::string& path) {
    VehicleConfig cfg;
    std::ifstream f(path);
    if (!f.is_open()) return cfg;
    // Minimal parser: expects lines key=value or wheel: x,y,z,radius
    std::string line;
    while (std::getline(f, line)) {
        if (line.rfind("name=",0)==0) cfg.name = line.substr(5);
        else if (line.rfind("mass=",0)==0) cfg.mass = std::stof(line.substr(5));
        else if (line.rfind("wheel=",0)==0) {
            std::stringstream ss(line.substr(6));
            WheelDesc wd{}; char comma;
            ss >> wd.position.x >> comma >> wd.position.y >> comma >> wd.position.z >> comma >> wd.radius;
            wd.suspensionRest = 0.4f; wd.suspensionStiffness=20000.0f; wd.suspensionDamping=3000.0f;
            cfg.wheels.push_back(wd);
        }
    }
    if (cfg.wheels.empty()) {
        cfg.wheels.push_back({{-3, -0.5f, 3},0.5f,0.4f,20000.0f,3000.0f});
        cfg.wheels.push_back({{3, -0.5f, 3},0.5f,0.4f,20000.0f,3000.0f});
        cfg.wheels.push_back({{-3, -0.5f, -3},0.5f,0.4f,20000.0f,3000.0f});
        cfg.wheels.push_back({{3, -0.5f, -3},0.5f,0.4f,20000.0f,3000.0f});
    }
    if (cfg.doors.empty()) { cfg.doors.push_back({"Front",2.0f}); cfg.doors.push_back({"Middle",2.5f}); }
    return cfg;
}
}
