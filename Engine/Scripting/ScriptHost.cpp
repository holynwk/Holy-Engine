#include "ScriptHost.h"

namespace ote::scripting {
bool ScriptHost::Initialize() {
    lua_.open_libraries(sol::lib::base, sol::lib::math, sol::lib::table, sol::lib::string);
    return true;
}

void ScriptHost::BindVehicleAPI(VehicleAPI* api) {
    lua_.new_usertype<VehicleAPI>("VehicleAPI",
        "getSpeedKmh", &VehicleAPI::GetSpeedKmh,
        "setLights", &VehicleAPI::SetLights,
        "toggleDoor", &VehicleAPI::ToggleDoor,
        "airPressure", &VehicleAPI::AirPressure);
    lua_["vehicle"] = api;
}
}
