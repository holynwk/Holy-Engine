# OpenTransitEngine Architecture

OpenTransitEngine is a modular C++20 simulator runtime focused on realistic bus physics and data-driven content. Key pillars:

- **Platform**: SDL2 windowing/input abstraction.
- **Renderer**: Vulkan-based forward+ style renderer with a minimal render graph, debug draw, and ImGui overlay.
- **Scene**: EnTT-based ECS, transform hierarchy, serialization/streaming of map chunks.
- **Physics**: Jolt physics world wrapper with fixed-step loop and queries API.
- **Vehicles**: Custom wheel-suspension-tire model, drivetrain, pneumatics, ABS/ASR, articulation.
- **TransitSim**: Systems for doors, electrical, instruments, passengers, routes, simple traffic.
- **Scripting**: Lua via sol2, VehicleAPI exposes safe surface for cockpit scripts.
- **Telemetry**: CSV recorder and debug overlay with profiling hooks.

Subsystems communicate through lightweight interfaces and ECS components. All per-frame allocations are avoided by preallocation and stack arenas. Physics LOD and streaming allow scaling to larger scenes.
