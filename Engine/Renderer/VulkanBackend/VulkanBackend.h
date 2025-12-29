#pragma once
#include <vector>
#include "../Camera.h"
#include "../DebugDraw.h"

namespace ote::renderer {
class VulkanBackend {
public:
    bool Initialize(void* windowHandle);
    void BeginFrame();
    void Render(const std::vector<Renderable>& renderables, const Camera& camera, DebugDraw& debugDraw);
    void Shutdown();
};
}
