#include "Streaming.h"
#include <cmath>

namespace ote::scene {
std::vector<Chunk> Streaming::ActiveChunks(const glm::vec3& position) const {
    std::vector<Chunk> active;
    for (const auto& c : chunks_) {
        float dist = glm::length(position - c.center);
        if (dist < c.radius) active.push_back(c);
    }
    return active;
}
}
