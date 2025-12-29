#include "JobSystem.h"

namespace ote::core {
JobSystem& JobSystem::Instance() {
    static JobSystem js;
    return js;
}

void JobSystem::Start(size_t threadCount) {
    running_ = true;
    if (threadCount == 0) threadCount = 1;
    for (size_t i = 0; i < threadCount; ++i) {
        workers_.emplace_back([this]() { Worker(); });
    }
}

void JobSystem::Stop() {
    {
        std::unique_lock<std::mutex> lock(mutex_);
        running_ = false;
    }
    cv_.notify_all();
    for (auto& w : workers_) {
        if (w.joinable()) w.join();
    }
    workers_.clear();
}

void JobSystem::Enqueue(const std::function<void()>& job) {
    {
        std::unique_lock<std::mutex> lock(mutex_);
        jobs_.push(job);
    }
    cv_.notify_one();
}

void JobSystem::Worker() {
    while (true) {
        std::function<void()> job;
        {
            std::unique_lock<std::mutex> lock(mutex_);
            cv_.wait(lock, [this]() { return !jobs_.empty() || !running_; });
            if (!running_ && jobs_.empty()) break;
            job = jobs_.front();
            jobs_.pop();
        }
        job();
    }
}
}
