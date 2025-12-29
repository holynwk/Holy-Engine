#include "TransformSystem.h"
#include <glm/gtc/matrix_transform.hpp>

namespace ote::scene {
glm::mat4 TransformSystem::Compose(const Transform& t) {
    glm::mat4 m(1.0f);
    m = glm::translate(m, t.position);
    m = glm::rotate(m, t.rotation.x, glm::vec3(1,0,0));
    m = glm::rotate(m, t.rotation.y, glm::vec3(0,1,0));
    m = glm::rotate(m, t.rotation.z, glm::vec3(0,0,1));
    m = glm::scale(m, t.scale);
    return m;
}
}
