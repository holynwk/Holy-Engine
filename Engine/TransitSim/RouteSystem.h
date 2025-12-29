#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>

namespace ote::transit {
struct StopPoint { std::string name; glm::vec3 position; };

class RouteSystem {
public:
    void SetStops(const std::vector<StopPoint>& stops) { stops_ = stops; }
    const StopPoint* CurrentStop() const { if (current_ < stops_.size()) return &stops_[current_]; return nullptr; }
    void Update(const glm::vec3& busPos, float speedKmh);
private:
    std::vector<StopPoint> stops_;
    size_t current_ = 0;
};
}
