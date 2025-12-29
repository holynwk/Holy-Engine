#pragma once
#include <vector>
#include <string>

namespace ote::transit {
enum class DoorState { Closed, Opening, Open, Closing };
struct Door { std::string name; DoorState state=DoorState::Closed; float timer=0.0f; float openTime=2.0f; };

class DoorSystem {
public:
    void Configure(const std::vector<std::string>& names);
    void Toggle(size_t idx);
    void Update(float dt);
    const std::vector<Door>& Doors() const { return doors_; }
private:
    std::vector<Door> doors_;
};
}
