#pragma once

namespace ote::vehicles {
class Pneumatics {
public:
    void Update(float dt, float consumption) {
        pressure_ += (compressorRate_ - consumption) * dt;
        if (pressure_ < 0) pressure_ = 0; if (pressure_ > maxPressure_) pressure_ = maxPressure_;
    }
    float Pressure() const { return pressure_; }
private:
    float pressure_ = 8.0f; // bar
    float maxPressure_ = 10.0f;
    float compressorRate_ = 0.5f;
};
}
