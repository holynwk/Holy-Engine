#pragma once
#include <vector>
#include <glm/glm.hpp>

namespace ote::renderer {
struct MeshVertex { glm::vec3 position; glm::vec3 normal; glm::vec2 uv; };
struct Mesh {
    std::vector<MeshVertex> vertices;
    std::vector<uint32_t> indices;
};
Mesh CreateCube();
}
