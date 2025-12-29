#pragma once
#include <chrono>
#include <string>
#include "Logger.h"

namespace ote::core {
class ProfileScope {
public:
    ProfileScope(const std::string& label) : label_(label), start_(Clock::now()) {}
    ~ProfileScope() {
        auto end = Clock::now();
        double ms = std::chrono::duration<double, std::milli>(end - start_).count();
        Logger::Instance().Log(Logger::Level::Trace, label_ + " took " + std::to_string(ms) + " ms");
    }
private:
    using Clock = std::chrono::high_resolution_clock;
    std::string label_;
    Clock::time_point start_;
};
}
