#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>

namespace ote::scene {
struct Chunk { std::string name; glm::vec3 center{0}; float radius = 100.0f; };

class Streaming {
public:
    void SetChunks(const std::vector<Chunk>& chunks) { chunks_ = chunks; }
    std::vector<Chunk> ActiveChunks(const glm::vec3& position) const;
private:
    std::vector<Chunk> chunks_;
};
}
