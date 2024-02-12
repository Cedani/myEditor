#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace cedx {
    namespace render {
        class ShaderProgram{
            public:
                ShaderProgram(const std::string &vfp, const std::string &ffp);
                ~ShaderProgram();

                void start();
                void stop();
            protected:
                // void binder();
                void bindAttributes(int attribNumber, const std::string &variableName);
                virtual void getAllUniformLocations() = 0;
                int getShaderUniformLocation(const std::string &uniName);
                void loadFloat(int location, float value);
                void loadVector3(int location, const glm::vec3 &value);
                void loadMatrix(int location, const glm::mat4 &value);
                void loadBoolean(int location, bool value);
                void validateProgram();

            private:
                GLuint loadShader(const std::string &fp, int type);
                GLuint _programID;
                GLuint _vertexShaderID;
                GLuint _fragmentShaderID;
        };
    }
}