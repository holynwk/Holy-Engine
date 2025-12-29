#include "PhysicsWorld.h"

namespace ote::physics {
RigidBody* PhysicsWorld::CreateBody() {
    bodies_.push_back({});
    return &bodies_.back();
}

void PhysicsWorld::Step(float dt) {
    ote::core::ProfileScope scope("PhysicsWorld::Step");
    for (auto& b : bodies_) {
        b.position += b.velocity * dt;
    }
}
}
