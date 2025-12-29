#pragma once
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

namespace ote::core {
class JobSystem {
public:
    static JobSystem& Instance();
    void Start(size_t threadCount = std::thread::hardware_concurrency());
    void Stop();
    void Enqueue(const std::function<void()>& job);
private:
    JobSystem() = default;
    void Worker();
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> jobs_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool running_ = false;
};
}
