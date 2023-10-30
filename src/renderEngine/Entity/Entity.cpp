#include "Entity.hpp"

cedx::render::Entity::Entity(TexturedModel &model, const glm::vec3 &pos, const glm::vec3 &rot, const float &scale): _model(model), _position(pos), _rotation(rot), _scale(scale)
{

}

cedx::render::Entity::~Entity()
{

}

cedx::render::TexturedModel &cedx::render::Entity::getModel() const
{
    return _model;
}

const glm::vec3 &cedx::render::Entity::getPosition() const
{
    return _position;
}

const glm::vec3 &cedx::render::Entity::getRotation() const
{
    return _rotation;
}

const float &cedx::render::Entity::getScale() const
{
    return _scale;
}

void cedx::render::Entity::changePosition(const float &dx, const float &dy, const float &dz)
{
    _position.x += dx;
    _position.y += dy;
    _position.z += dz;
}

void cedx::render::Entity::changeRotation(const float &dx, const float &dy, const float &dz)
{
    _rotation.x += dx;
    _rotation.y += dy;
    _rotation.z += dz;
}