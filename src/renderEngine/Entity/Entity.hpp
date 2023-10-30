#pragma once
#include "TexturedModel.hpp"
#include <glm/glm.hpp>

namespace cedx {
    namespace render {
        class Entity {
            public:
                Entity(TexturedModel &model, const glm::vec3 &pos, const glm::vec3 &rot, const float &scale);
                ~Entity();

                TexturedModel &getModel() const;
                const glm::vec3 &getPosition() const;
                const glm::vec3 &getRotation() const;
                const float &getScale() const;

                void changePosition(const float &dx, const float &dy, const float &dz);
                void changeRotation(const float &rx, const float &ry, const float &rz);

            private:
                TexturedModel &_model;
                glm::vec3 _position;
                glm::vec3 _rotation;
                float _scale;
        };
    }
}