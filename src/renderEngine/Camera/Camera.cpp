#include "Camera.hpp"

cedx::render::Camera::Camera(): _position(glm::vec3(0, 0, 0)), _pitch(0.f), _roll(0.f), _yaw(0.f)
{

}

cedx::render::Camera::~Camera()
{
}

const glm::vec3 &cedx::render::Camera::getPosition() const
{
    return _position;
}

const float &cedx::render::Camera::getPitch() const
{
    return _pitch;
}

const float &cedx::render::Camera::getRoll() const
{
    return _roll;
}

const float &cedx::render::Camera::getYaw() const
{
    return _yaw;
}

void cedx::render::Camera::move(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            _position.z -= 0.02f;
        }
        if (event.key.code == sf::Keyboard::Down) {
            _position.z += 0.02f;
        }
        if (event.key.code == sf::Keyboard::Left) {
            _position.x -= 0.02f;
        }
        if (event.key.code == sf::Keyboard::Right) {
            _position.x += 0.02f;
        }
    }
}