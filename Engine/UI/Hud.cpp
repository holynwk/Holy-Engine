#include "Hud.h"
#include <sstream>

namespace ote::ui {
void Hud::Render(const ote::transit::InstrumentData& data) {
    std::stringstream ss;
    ss << "SPD:" << data.speedKmh << "km/h RPM:" << data.rpm << " G:" << data.gear << " AIR:" << data.airPressure;
    lastText_ = ss.str();
}
}
