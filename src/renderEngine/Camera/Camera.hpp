#pragma once
#include <glm/glm.hpp>
#include <SFML/Window/Event.hpp>

namespace cedx {
    namespace render {
        class Camera {
            public:
                Camera();
                ~Camera();

                const glm::vec3 &getPosition() const;
                const float &getPitch() const;
                const float &getRoll() const;
                const float &getYaw() const;
                

                void move(const sf::Event &event);
            private:
                glm::vec3 _position;
                float _pitch;
                float _yaw;
                float _roll;
        };
    }
}