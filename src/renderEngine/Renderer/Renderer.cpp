#include "Renderer.hpp"

cedx::render::Renderer::Renderer(StaticShader &shader, const float &w, const float &h): _projectionMatrix(glm::mat4(1.0f))
{
    createProjectionMatrix(w, h);
    shader.start();
    shader.loadProjectionMatrix(_projectionMatrix);
    shader.stop();
}

cedx::render::Renderer::~Renderer()
{
}

void cedx::render::Renderer::prepare()
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 1, 1);
}

void cedx::render::Renderer::render(RawModel &model)
{
    glBindVertexArray(model.getVao());
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void cedx::render::Renderer::render(TexturedModel &model)
{
    glBindVertexArray(model.getRawModel().getVao());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glActiveTexture(GL_TEXTURE0);
    sf::Texture::bind(&model.getTexture().getTexture());
    glDrawElements(GL_TRIANGLES, model.getRawModel().getVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

void cedx::render::Renderer::render(Entity &entity, StaticShader &shader)
{
    TexturedModel &model = entity.getModel();
    glBindVertexArray(model.getRawModel().getVao());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glm::mat4 transformationMatrix = cedx::Math::createTransformationMatrix(entity.getPosition(), entity.getRotation(), entity.getScale());
    shader.loadTransformationMatrix(transformationMatrix);
    glActiveTexture(GL_TEXTURE0);
    sf::Texture::bind(&(model.getTexture().getTexture()));
    glDrawElements(GL_TRIANGLES, model.getRawModel().getVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

void cedx::render::Renderer::createProjectionMatrix(float width, float height)
{
    float aspectRatio = (float)width / height;
    float y_scale = (1.0f / glm::tan(glm::radians(_fov / 2.0f))) * aspectRatio;
    float x_scale = y_scale / aspectRatio;
    float frustum_length = _farPlane - _nearPlane;

    // _projectionMatrix = glm::mat4(
    //     glm::vec4(x_scale, 0, 0, 0),
    //     glm::vec4(0, y_scale, 0, 0),
    //     glm::vec4(0, 0, -((_farPlane + _nearPlane) / frustum_length), -1),
    //     glm::vec4(0, 0, -((2 * _farPlane * _nearPlane) / frustum_length), 0)
    // );
    _projectionMatrix[0][0] = x_scale;
    _projectionMatrix[1][1] = y_scale;
    _projectionMatrix[2][2] = -((_farPlane + _nearPlane) / frustum_length);
    _projectionMatrix[2][3] = -1;
    _projectionMatrix[3][2] = -((2 * _nearPlane * _farPlane) / frustum_length);
    _projectionMatrix[3][3] = 0;
}