#pragma once
#include <functional>

namespace ote::physics {
class FixedStep {
public:
    FixedStep(double hz) : dt_(1.0 / hz) {}
    template<typename Func>
    void Tick(double realDelta, Func&& func) {
        accumulator_ += realDelta;
        while (accumulator_ >= dt_) {
            func(static_cast<float>(dt_));
            accumulator_ -= dt_;
        }
    }
    double Dt() const { return dt_; }
private:
    double dt_;
    double accumulator_ = 0.0;
};
}
