#include "RouteSystem.h"

namespace ote::transit {
void RouteSystem::Update(const glm::vec3& busPos, float speedKmh) {
    if (current_ >= stops_.size()) return;
    auto delta = busPos - stops_[current_].position;
    if (glm::length(delta) < 3.0f && speedKmh < 5.0f) {
        current_++;
    }
}
}
