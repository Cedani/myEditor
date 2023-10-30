#include "StaticShader.hpp"

cedx::render::StaticShader::StaticShader(): ShaderProgram(SIMPLE_VERT, SIMPLE_FRAG), _locationTransformationMatrix(-1)
{
    bindAttributes(0, "position");
    bindAttributes(1, "textureCoords");
    validateProgram();
    getAllUniformLocations();
}

cedx::render::StaticShader::~StaticShader()
{
}

void cedx::render::StaticShader::getAllUniformLocations()
{
    _locationTransformationMatrix = getShaderUniformLocation("transformationMatrix");
    _locationProjectionMatrix = getShaderUniformLocation("projectionMatrix");
    _locationViewMatrix = getShaderUniformLocation("viewMatrix");
}

void cedx::render::StaticShader::loadTransformationMatrix(const glm::mat4 &matrix)
{
    loadMatrix(_locationTransformationMatrix, matrix);
}

void cedx::render::StaticShader::loadProjectionMatrix(const glm::mat4 &matrix)
{
    loadMatrix(_locationProjectionMatrix, matrix);
}

void cedx::render::StaticShader::loadViewMatrix(const cedx::render::Camera &camera)
{
    loadMatrix(_locationViewMatrix, Math::createViewMatrix(camera));
}