#pragma once
#include <chrono>

namespace ote::core {
class Time {
public:
    using Clock = std::chrono::steady_clock;
    static Time& Instance();
    void Tick();
    double DeltaSeconds() const { return deltaSeconds_; }
    double ElapsedSeconds() const;
private:
    Time();
    Clock::time_point last_; 
    double deltaSeconds_ = 0.0;
};
}
