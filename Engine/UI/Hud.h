#pragma once
#include <string>
#include "../TransitSim/InstrumentSystem.h"

namespace ote::ui {
class Hud {
public:
    void Render(const ote::transit::InstrumentData& data);
    std::string LastText() const { return lastText_; }
private:
    std::string lastText_;
};
}
