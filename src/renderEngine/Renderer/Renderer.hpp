#pragma once
#include <glad/glad.h>
#include "RawModel.hpp"
#include "TexturedModel.hpp"
#include "Entity.hpp"
#include "libMath.hpp"
#include "StaticShader.hpp"

namespace cedx {
    namespace render {
        class Renderer {
            public:
                Renderer(StaticShader &shader, const float &w = 800, const float &h = 600);
                ~Renderer();

                void prepare();
                void render(RawModel &model);
                void render(TexturedModel &model);
                void render(Entity &entity, StaticShader &shader);

                void createProjectionMatrix(float width, float height);
            private:
                glm::mat4 _projectionMatrix;
                float _fov = 70.0f;
                float _nearPlane = 0.1f;
                float _farPlane = 1000.0f;
        };
    }
}