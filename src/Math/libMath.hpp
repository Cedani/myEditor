#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Camera.hpp"

namespace cedx {
    namespace Math {
        glm::mat4 createTransformationMatrix(const glm::vec3 &translation, const glm::vec3 &rotation, float scale);
        glm::mat4 createViewMatrix(const render::Camera &);
    }
}