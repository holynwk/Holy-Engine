#pragma once

namespace ote::vehicles {
class BrakeSystem {
public:
    void SetInputs(float service, bool parking) { service_ = service; parking_ = parking; }
    float BrakeForce(float pressure) const { return (service_ + (parking_?1.0f:0.0f)) * pressure * 1000.0f; }
private:
    float service_ = 0.0f;
    bool parking_ = false;
};
}
