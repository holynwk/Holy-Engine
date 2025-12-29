#pragma once
#include "../Vehicles/VehicleController.h"
#include "../TransitSim/DoorSystem.h"

namespace ote::scripting {
class VehicleAPI {
public:
    VehicleAPI(ote::vehicles::VehicleController* controller, ote::transit::DoorSystem* doors)
    : controller_(controller), doors_(doors) {}
    float GetSpeedKmh() const { return controller_->SpeedKmh(); }
    void SetLights(bool on) { lights_ = on; }
    void ToggleDoor(int idx) { doors_->Toggle(static_cast<size_t>(idx)); }
    float AirPressure() const { return controller_->AirPressure(); }
private:
    ote::vehicles::VehicleController* controller_;
    ote::transit::DoorSystem* doors_;
    bool lights_ = false;
};
}
