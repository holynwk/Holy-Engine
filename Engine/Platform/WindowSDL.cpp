#include "WindowSDL.h"
#include <SDL2/SDL.h>
#include "../Core/Logger.h"

namespace ote::platform {
bool WindowSDL::Create(const std::string& title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        ote::core::Logger::Instance().Log(ote::core::Logger::Level::Error, "SDL init failed");
        return false;
    }
    window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
    if (!window_) return false;
    return true;
}

void WindowSDL::PollEvents(const std::function<void(int key, bool down)>& onKey) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) shouldClose_ = true;
        if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
            onKey(static_cast<int>(e.key.keysym.sym), e.type == SDL_KEYDOWN);
        }
    }
}

void WindowSDL::Swap() {
    // Swap handled by renderer backend; placeholder
}

void WindowSDL::Destroy() {
    if (window_) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
    SDL_Quit();
}
}
