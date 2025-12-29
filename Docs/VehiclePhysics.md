# Vehicle Physics Overview

OpenTransitEngine implements a raycast-based suspension and brush tire model to capture heavy-vehicle behavior.

- **Fixed Step**: Physics tick at 200 Hz for LOD0 vehicles, 100 Hz for LOD1, 10 Hz for LOD2 kinematics.
- **Suspension**: Each wheel raycasts to ground, computing spring compression and damping. Anti-roll bars couple left/right wheels.
- **Tire Forces**: Slip ratio/angle feed brush-like curves to derive longitudinal/lateral forces. Rolling resistance and aero drag are applied.
- **Drivetrain**: Engine torque curve, automatic gearbox with configurable shift points and delays, retarder option.
- **Brakes**: Pneumatic service brake modulated by reservoir pressure, parking brake latch, ABS pulsation under high slip.
- **Pneumatics**: Compressor fills reservoir, consumers (service brake, doors) reduce pressure; pressure influences max brake torque.
- **Articulation**: Articulated buses link two bodies with constrained joint, damped to avoid jackknifing.
- **Physics LOD**: Distant vehicles downgrade to simplified integration and spline following to save CPU.
