# OpenTransitEngine

OpenTransitEngine is a C++20 MVP for a modern bus simulator runtime inspired by classics but built on a home-grown stack.

## Stack Choice
- **Renderer**: Vulkan (chosen for explicit control and portability). The backend is stubbed for text CI but structured for a Vulkan pipeline.
- **Physics**: Custom integration with placeholders for Jolt/Bullet; interfaces allow swapping. Fixed-step loop handles vehicle dynamics.
- **Scripting**: Lua via sol2 for cockpit logic and triggers.

## Repository Structure
- `Engine/` core runtime (Core, Platform, Renderer, Scene, Physics, Vehicles, TransitSim, Scripting, UI, Telemetry)
- `Apps/Sandbox` interactive demo
- `Content/` built-in map and vehicles
- `Tools/ContentCooker` asset validator stub
- `Docs/` architecture and design notes
- `Tests/` sanity executable

## Building
```
cmake -S . -B build
cmake --build build
```
Dependencies SDL2, Vulkan SDK, and a C++20 compiler are expected on the host; FetchContent pulls glm/entt/sol2. In constrained environments the stub targets still compile but rendering features may be minimal.

## Running
After building, run `build/Sandbox`. The demo spawns Bus12m on the DepotTestTrack map. Telemetry writes `telemetry.csv`.

### Controls
- W/S throttle/brake
- Space parking brake
- E toggle door 1
- I ignition
- L headlights (via script placeholder)
- C switch camera (future)
- P/O add/remove passengers (future binding)
- F1 debug overlay

## Adding a Vehicle
1. Create a folder under `Content/Vehicles/<Name>/` with `VehicleConfig.json` lines `name=...`, `mass=...`, `wheel=x,y,z,radius`.
2. Author Lua cockpit script in `Engine/Scripting/ExampleScripts` and bind in code.
3. Extend `Sandbox` to load your config path.

## Known Limitations
- Vulkan backend is a stub; visuals are minimal in this MVP text environment.
- Physics uses simplified placeholders; tire and pneumatic behavior need full implementation.
- ContentCooker does not yet process glTF/textures.

## Roadmap
- Implement full Vulkan render graph with PBR materials, shadow maps, and skybox.
- Integrate real Jolt/Bullet backend with articulated joint and wheel raycasts.
- Expand vehicle LOD transitions and traffic AI.
- Add proper Lua-driven dashboards and interactive electrical/door panels.
