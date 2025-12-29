#pragma once
#include <vector>

namespace ote::vehicles {
struct TorqueSample { float rpm; float torque; };
class Drivetrain {
public:
    void SetCurve(const std::vector<TorqueSample>& samples) { curve_ = samples; }
    float SampleTorque(float rpm) const {
        if (curve_.empty()) return 0.0f;
        return curve_.front().torque;
    }
private:
    std::vector<TorqueSample> curve_;
};
}
