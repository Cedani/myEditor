#include "Loader.hpp"

cedx::render::Loader::Loader()
{
}

cedx::render::Loader::~Loader()
{
    for (const auto &vao: _vaos)
        glDeleteVertexArrays(1, &vao);

    for (const auto &vbo: _vbos)
        glDeleteBuffers(1, &vbo);
}

cedx::render::RawModel cedx::render::Loader::loadToVAO(std::vector<GLfloat> positions, std::vector<GLfloat> textCoord, std::vector<GLuint> indices)
{
    GLuint vaoID = createVAO();

    storeDataInAttributeList(0, 3, positions);
    storeDataInAttributeList(1, 2, textCoord);
    bindIndecesBuffer(indices);
    unbindVAO();
    return RawModel(vaoID, indices.size());
}

GLuint cedx::render::Loader::createVAO()
{
    GLuint VAO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    _vaos.push_back(VAO);
    return (VAO);
}

void cedx::render::Loader::unbindVAO()
{
    glBindVertexArray(0);
}

void cedx::render::Loader::storeDataInAttributeList(int attribNumber, int coordSize, std::vector<GLfloat> data)
{
    GLuint VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(attribNumber, coordSize, GL_FLOAT, false, 0, 0);
    _vbos.push_back(VBO);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void cedx::render::Loader::bindIndecesBuffer(std::vector<GLuint> indices)
{
    GLuint VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size() ,indices.data(), GL_STATIC_DRAW);
    _vbos.push_back(VBO);
}

sf::Texture &cedx::render::Loader::loadTexture(const std::string &fp)
{
    sf::Texture &newTexture = _textures.emplace_back();
    if (!newTexture.loadFromFile(fp)) {
        std::cerr << "could not load texture" << std::endl;
        exit(84);
    }
    return newTexture;
}