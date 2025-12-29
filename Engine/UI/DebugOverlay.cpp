#include "DebugOverlay.h"
#include <sstream>

namespace ote::ui {
std::string DebugOverlay::Text() const {
    std::stringstream ss;
    ss << "FPS:" << last_.fps << " Frame:" << last_.frameMs << "ms Physics:" << last_.physicsMs << "ms Chunks:" << last_.activeChunks;
    ss << " L0:" << last_.vehiclesLod0 << " L1:" << last_.vehiclesLod1 << " L2:" << last_.vehiclesLod2;
    return ss.str();
}
}
