#include "libMath.hpp"


glm::mat4 cedx::Math::createTransformationMatrix(const glm::vec3 &translation, const glm::vec3 &rotation, float scale)
{
    glm::mat4 value = glm::translate(glm::mat4(1.0f), translation);
    value = glm::rotate(value, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    value = glm::rotate(value, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    value = glm::rotate(value, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    value = glm::scale(value, glm::vec3(scale, scale, scale));
    return value;
}

glm::mat4 cedx::Math::createViewMatrix(const cedx::render::Camera &camera)
{
    glm::vec3 negativeCamPos = -camera.getPosition();
    glm::mat4 viewMatrix = glm::rotate(glm::mat4(1.0), glm::radians(camera.getPitch()), glm::vec3(1, 0, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(camera.getYaw()), glm::vec3(0, 1, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(camera.getRoll()), glm::vec3(0, 0, 1));
    viewMatrix = glm::translate(viewMatrix, negativeCamPos);
    return viewMatrix;
}