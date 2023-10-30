#pragma once
#include "ShaderProgram.hpp"
#include "utilsRender.h"
#include "libMath.hpp"

namespace cedx
{
    namespace render
    {
        class StaticShader : public ShaderProgram
        {
            public:
                StaticShader();
                ~StaticShader();

                void loadTransformationMatrix(const glm::mat4 &matrix);
                void loadProjectionMatrix(const glm::mat4 &matrix);
                void loadViewMatrix(const Camera &);
            protected:
                // void bindAttributes() override;
                void getAllUniformLocations() final;

            private:
                int _locationTransformationMatrix;
                int _locationProjectionMatrix;
                int _locationViewMatrix;

        };
    }
}