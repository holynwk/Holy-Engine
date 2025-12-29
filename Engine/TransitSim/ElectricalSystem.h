#pragma once

namespace ote::transit {
class ElectricalSystem {
public:
    void SetIgnition(bool on) { ignition_ = on; }
    bool Ignition() const { return ignition_; }
    float Voltage() const { return ignition_ ? 27.0f : 24.0f; }
private:
    bool ignition_ = false;
};
}
