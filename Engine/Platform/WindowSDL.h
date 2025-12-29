#pragma once
#include <string>
#include <functional>

struct SDL_Window;

namespace ote::platform {
class WindowSDL {
public:
    bool Create(const std::string& title, int width, int height);
    void PollEvents(const std::function<void(int key, bool down)>& onKey);
    void Swap();
    void Destroy();
    bool ShouldClose() const { return shouldClose_; }
    void* GetNativeHandle() const { return window_; }
private:
    SDL_Window* window_ = nullptr;
    bool shouldClose_ = false;
};
}
