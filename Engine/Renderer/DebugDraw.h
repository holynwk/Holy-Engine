#pragma once
#include <vector>
#include <glm/glm.hpp>

namespace ote::renderer {
struct DebugLine { glm::vec3 a; glm::vec3 b; glm::vec3 color; };

class DebugDraw {
public:
    void Clear() { lines_.clear(); }
    void AddLine(const glm::vec3& a, const glm::vec3& b, const glm::vec3& color) { lines_.push_back({a,b,color}); }
    const std::vector<DebugLine>& Lines() const { return lines_; }
private:
    std::vector<DebugLine> lines_;
};
}
