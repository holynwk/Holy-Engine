#pragma once
#include <vector>
#include <glm/glm.hpp>

namespace ote::transit {
struct TrafficAgent { glm::vec3 position{0}; glm::vec3 target{0}; float speed=10.0f; };

class TrafficSystem {
public:
    void SetAgents(const std::vector<TrafficAgent>& agents) { agents_ = agents; }
    void Update(float dt);
    const std::vector<TrafficAgent>& Agents() const { return agents_; }
private:
    std::vector<TrafficAgent> agents_;
};
}
