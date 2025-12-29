#pragma once

namespace ote::transit {
class PassengerSystem {
public:
    void Add(int count) { passengers_ += count; if (passengers_ < 0) passengers_ = 0; }
    int Count() const { return passengers_; }
    float ExtraMass() const { return passengers_ * 70.0f; }
private:
    int passengers_ = 0;
};
}
