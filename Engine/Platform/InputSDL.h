#pragma once
#include <unordered_map>

namespace ote::platform {
class InputSDL {
public:
    void SetKeyState(int key, bool down) { keys_[key] = down; }
    bool IsDown(int key) const {
        auto it = keys_.find(key);
        return it != keys_.end() && it->second;
    }
private:
    std::unordered_map<int, bool> keys_;
};
}
