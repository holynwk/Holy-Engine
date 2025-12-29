#pragma once
#include <sol/sol.hpp>
#include <string>
#include "VehicleAPI.h"

namespace ote::scripting {
class ScriptHost {
public:
    bool Initialize();
    sol::state& Lua() { return lua_; }
    void BindVehicleAPI(VehicleAPI* api);
private:
    sol::state lua_;
};
}
