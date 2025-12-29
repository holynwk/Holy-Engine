#pragma once

namespace ote::vehicles {
class ABS_ASR {
public:
    float ModulateBrake(float slip, float input) const { return slip > slipLimit_ ? input * 0.5f : input; }
    float ModulateDrive(float slip, float torque) const { return slip > slipLimit_ ? torque * 0.5f : torque; }
private:
    float slipLimit_ = 0.2f;
};
}
