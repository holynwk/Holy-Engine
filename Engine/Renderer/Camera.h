#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace ote::renderer {
class Camera {
public:
    void SetPerspective(float fov, float aspect, float nearZ, float farZ) {
        projection_ = glm::perspective(glm::radians(fov), aspect, nearZ, farZ);
    }
    void SetView(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up) {
        view_ = glm::lookAt(eye, target, up);
        position_ = eye;
    }
    const glm::mat4& View() const { return view_; }
    const glm::mat4& Projection() const { return projection_; }
    const glm::vec3& Position() const { return position_; }
private:
    glm::mat4 view_{1.0f};
    glm::mat4 projection_{1.0f};
    glm::vec3 position_{0.0f};
};
}
