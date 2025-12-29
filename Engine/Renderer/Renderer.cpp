#include "Renderer.h"
#include "VulkanBackend/VulkanBackend.h"
#include "../Core/Logger.h"

namespace ote::renderer {
static VulkanBackend g_backend;

bool Renderer::Initialize(void* windowHandle) {
    return g_backend.Initialize(windowHandle);
}

void Renderer::BeginFrame() {
    renderables_.clear();
    g_backend.BeginFrame();
}

void Renderer::Submit(const Renderable& r) {
    renderables_.push_back(r);
}

void Renderer::Render(const Camera& camera) {
    g_backend.Render(renderables_, camera, debugDraw_);
}

void Renderer::Shutdown() {
    g_backend.Shutdown();
}
}
