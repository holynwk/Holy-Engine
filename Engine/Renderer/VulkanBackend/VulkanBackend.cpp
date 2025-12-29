#include "VulkanBackend.h"
#include "../../Core/Logger.h"

namespace ote::renderer {
bool VulkanBackend::Initialize(void* /*windowHandle*/) {
    ote::core::Logger::Instance().Log(ote::core::Logger::Level::Info, "Vulkan backend initialized (stub)");
    return true;
}

void VulkanBackend::BeginFrame() {
}

void VulkanBackend::Render(const std::vector<Renderable>& /*renderables*/, const Camera& /*camera*/, DebugDraw& /*debugDraw*/) {
    // Stub renderer for MVP text environment
}

void VulkanBackend::Shutdown() {
}
}
