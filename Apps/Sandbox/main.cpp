#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "../../Engine/Platform/WindowSDL.h"
#include "../../Engine/Platform/InputSDL.h"
#include "../../Engine/Core/Time.h"
#include "../../Engine/Core/JobSystem.h"
#include "../../Engine/Renderer/Renderer.h"
#include "../../Engine/Scene/ECSWorld.h"
#include "../../Engine/Scene/TransformSystem.h"
#include "../../Engine/Physics/PhysicsWorld.h"
#include "../../Engine/Physics/FixedStep.h"
#include "../../Engine/Vehicles/VehicleController.h"
#include "../../Engine/TransitSim/DoorSystem.h"
#include "../../Engine/TransitSim/ElectricalSystem.h"
#include "../../Engine/TransitSim/InstrumentSystem.h"
#include "../../Engine/TransitSim/PassengerSystem.h"
#include "../../Engine/TransitSim/RouteSystem.h"
#include "../../Engine/TransitSim/TrafficSystem.h"
#include "../../Engine/Scripting/ScriptHost.h"
#include "../../Engine/UI/Hud.h"
#include "../../Engine/UI/DebugOverlay.h"
#include "../../Engine/Telemetry/TelemetryRecorder.h"

using namespace ote;

int main(int argc, char** argv) {
    core::Logger::Instance().Log(core::Logger::Level::Info, "Starting Sandbox");
    platform::WindowSDL window;
    platform::InputSDL input;
    if (!window.Create("OpenTransitEngine", 1280, 720)) return -1;

    renderer::Renderer renderer;
    renderer.Initialize(window.GetNativeHandle());

    scene::ECSWorld world;
    physics::PhysicsWorld physicsWorld;
    physics::RigidBody* busBody = physicsWorld.CreateBody();
    vehicles::VehicleConfig cfg = vehicles::LoadVehicleConfig("../../Content/Vehicles/Bus12m/VehicleConfig.json");
    vehicles::VehicleController bus(cfg, busBody);

    transit::DoorSystem doors; doors.Configure({"Front","Middle"});
    transit::ElectricalSystem electrical;
    transit::InstrumentSystem instruments;
    transit::PassengerSystem passengers;
    transit::RouteSystem route; route.SetStops({{"Depot Gate", {0,0,10}}, {"Test Stop", {0,0,150}}});

    scripting::VehicleAPI api(&bus, &doors);
    scripting::ScriptHost scripts; scripts.Initialize(); scripts.BindVehicleAPI(&api);

    ui::Hud hud;
    ui::DebugOverlay debug;
    telemetry::TelemetryRecorder telemetry; telemetry.Open("telemetry.csv");

    physics::FixedStep fixed(200.0);

    double time = 0.0; int frame=0;
    while (!window.ShouldClose() && frame < 200) {
        window.PollEvents([&](int key, bool down){ input.SetKeyState(key, down); });
        core::Time::Instance().Tick();
        double dt = core::Time::Instance().DeltaSeconds();
        time += dt; frame++;

        float throttle = input.IsDown(SDLK_w) ? 1.0f : 0.0f;
        float brake = input.IsDown(SDLK_s) ? 1.0f : 0.0f;
        bool parking = input.IsDown(SDLK_SPACE);
        bool ignition = input.IsDown(SDLK_i);
        if (input.IsDown(SDLK_e)) doors.Toggle(0);
        bus.SetInputs(throttle, brake, 0.0f, parking, ignition);

        fixed.Tick(dt, [&](float fdt){
            physicsWorld.Step(fdt);
            bus.Update(fdt, 0.0f);
            doors.Update(fdt);
            route.Update(busBody->position, bus.SpeedKmh());
        });

        renderer::Camera cam; cam.SetPerspective(70.0f, 16.0f/9.0f, 0.1f, 500.0f); cam.SetView(glm::vec3(0,5,-10), glm::vec3(0,0,0), {0,1,0});
        renderer.BeginFrame();
        renderer.Render(cam);

        transit::InstrumentData data; data.speedKmh = bus.SpeedKmh(); data.airPressure = bus.AirPressure();
        instruments.Update(data);
        hud.Render(data);
        ui::DebugData dbg; dbg.fps = 1.0f / (dt+1e-4f); debug.Update(dbg);
        float pos[3] = {busBody->position.x, busBody->position.y, busBody->position.z};
        telemetry.Record(time, cfg.name, pos, bus.SpeedKmh(), bus.AirPressure(), bus.LOD());
    }

    renderer.Shutdown();
    window.Destroy();
    return 0;
}
