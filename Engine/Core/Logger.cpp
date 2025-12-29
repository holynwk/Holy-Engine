#include "Logger.h"

namespace ote::core {
Logger& Logger::Instance() {
    static Logger instance;
    return instance;
}

void Logger::Log(Level level, const std::string& msg) {
    const char* prefix = "[INFO]";
    switch (level) {
        case Level::Trace: prefix = "[TRACE]"; break;
        case Level::Info: prefix = "[INFO]"; break;
        case Level::Warn: prefix = "[WARN]"; break;
        case Level::Error: prefix = "[ERROR]"; break;
    }
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << prefix << " " << msg << std::endl;
}
}
