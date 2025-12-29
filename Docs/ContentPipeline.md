# Content Pipeline

Content is data-driven through JSON and Lua. The ContentCooker tool validates and packs assets.

- **Maps**: Each map has a `MapConfig.json` with chunk list, spawn points, stop points, and traffic splines. Geometry can be authored as glTF or procedural primitives.
- **Vehicles**: Each vehicle has a `VehicleConfig.json` describing masses, wheels, suspension, drivetrain, pneumatics, doors, and lighting. Lua scripts implement dashboard logic.
- **Materials**: Simple PBR parameters (albedo/metallic/roughness) with PNG textures.
- **Scripts**: Lua scripts are sandboxed and interact via VehicleAPI only.
- **Telemetry**: CSV logs are emitted to `/Saved/Telemetry`.

ContentCooker steps:
1. Validate JSON schema and units.
2. Convert glTF meshes into internal binary mesh cache.
3. Compress textures to engine-friendly formats.
4. Build chunk streaming manifest.
