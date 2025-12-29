#pragma once
#include <string>

namespace ote::transit {
struct InstrumentData {
    float speedKmh = 0.0f;
    float rpm = 600.0f;
    int gear = 1;
    float airPressure = 8.0f;
};

class InstrumentSystem {
public:
    void Update(const InstrumentData& d) { data_ = d; }
    const InstrumentData& Data() const { return data_; }
private:
    InstrumentData data_;
};
}
