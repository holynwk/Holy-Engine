#pragma once
#include <vector>

namespace ote::vehicles {
class Transmission {
public:
    void SetGears(const std::vector<float>& gears) { gears_ = gears; }
    int Gear() const { return gear_; }
    float Ratio() const { return (gear_ >=0 && gear_ < (int)gears_.size()) ? gears_[gear_] : 1.0f; }
    void ShiftUp() { if (gear_ +1 < (int)gears_.size()) gear_++; }
    void ShiftDown() { if (gear_>0) gear_--; }
private:
    std::vector<float> gears_{1.0f,0.7f,0.5f};
    int gear_ = 0;
};
}
