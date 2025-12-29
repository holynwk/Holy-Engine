#include "Time.h"

namespace ote::core {
Time::Time() {
    last_ = Clock::now();
}

Time& Time::Instance() {
    static Time t;
    return t;
}

void Time::Tick() {
    auto now = Clock::now();
    deltaSeconds_ = std::chrono::duration<double>(now - last_).count();
    last_ = now;
}

double Time::ElapsedSeconds() const {
    return std::chrono::duration<double>(Clock::now() - last_).count();
}
}
