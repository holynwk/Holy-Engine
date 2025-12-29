#pragma once
#include <string>
#include <iostream>
#include <mutex>

namespace ote::core {
class Logger {
public:
    enum class Level { Trace, Info, Warn, Error };
    static Logger& Instance();
    void Log(Level level, const std::string& msg);
private:
    Logger() = default;
    std::mutex mutex_;
};
}
