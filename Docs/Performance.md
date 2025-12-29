# Performance Strategy

- **Physics LOD**: Vehicles swap between LOD0/1/2 based on distance to camera and player relevance. LOD0 runs full 200 Hz model, LOD1 simplifies tire/pneumatic modeling, LOD2 follows spline kinematics.
- **Job System**: Thread pool for parallel wheel/tire computations and render preparation.
- **Memory**: No dynamic allocations per tick; arenas and pre-sized vectors are reused.
- **Profiling**: Lightweight scopes with optional Tracy integration; DebugOverlay shows frame and physics timings.
- **Streaming**: Map chunks loaded/unloaded around player to control draw/physics workload.
