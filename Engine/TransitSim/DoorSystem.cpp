#include "DoorSystem.h"

namespace ote::transit {
void DoorSystem::Configure(const std::vector<std::string>& names) {
    doors_.clear();
    for (auto& n : names) doors_.push_back({n});
}

void DoorSystem::Toggle(size_t idx) {
    if (idx >= doors_.size()) return;
    auto& d = doors_[idx];
    if (d.state == DoorState::Closed || d.state == DoorState::Closing) { d.state = DoorState::Opening; d.timer = 0.0f; }
    else if (d.state == DoorState::Open || d.state == DoorState::Opening) { d.state = DoorState::Closing; d.timer = 0.0f; }
}

void DoorSystem::Update(float dt) {
    for (auto& d : doors_) {
        d.timer += dt;
        if (d.state == DoorState::Opening && d.timer >= d.openTime) { d.state = DoorState::Open; d.timer = 0.0f; }
        if (d.state == DoorState::Closing && d.timer >= d.openTime) { d.state = DoorState::Closed; d.timer = 0.0f; }
    }
}
}
