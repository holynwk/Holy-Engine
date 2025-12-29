#pragma once
#include <string>
#include <vector>

namespace ote::ui {
struct DebugData { float fps=0; float frameMs=0; float physicsMs=0; int activeChunks=0; int vehiclesLod0=0; int vehiclesLod1=0; int vehiclesLod2=0; };
class DebugOverlay {
public:
    void Update(const DebugData& data) { last_ = data; }
    std::string Text() const;
private:
    DebugData last_;
};
}
