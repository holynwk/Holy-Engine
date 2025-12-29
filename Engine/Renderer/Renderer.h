#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "Camera.h"
#include "DebugDraw.h"

namespace ote::renderer {
struct Renderable { glm::mat4 transform{1.0f}; };

class Renderer {
public:
    bool Initialize(void* windowHandle);
    void BeginFrame();
    void Submit(const Renderable& r);
    void Render(const Camera& camera);
    void Shutdown();
    DebugDraw& GetDebugDraw() { return debugDraw_; }
private:
    std::vector<Renderable> renderables_;
    DebugDraw debugDraw_;
};
}
