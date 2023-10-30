#pragma once
#include "RawModel.hpp"
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <SFML/Graphics/Texture.hpp>



namespace cedx {
    namespace render {
        class Loader {
            public:
                Loader();
                ~Loader();

                RawModel loadToVAO(std::vector<GLfloat> positions, std::vector<GLfloat> textCoord, std::vector<GLuint> indices);
                sf::Texture &loadTexture(const std::string &fp);
                
            private:
                GLuint createVAO();
                void storeDataInAttributeList(int attribNumber, int coordSize, std::vector<GLfloat> data);
                void unbindVAO();
                void bindIndecesBuffer(std::vector<GLuint> indices);

                std::vector<GLuint> _vaos;
                std::vector<GLuint> _vbos;
                std::vector<sf::Texture> _textures;
        
        };
    }
}