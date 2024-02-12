#include <ShaderProgram.hpp>

cedx::render::ShaderProgram::ShaderProgram(const std::string &vfp, const std::string &ffp)
{
    _vertexShaderID = loadShader(vfp, GL_VERTEX_SHADER);
    _fragmentShaderID = loadShader(ffp, GL_FRAGMENT_SHADER);
    _programID = glCreateProgram();
    glAttachShader(_programID, _vertexShaderID);
    glAttachShader(_programID, _fragmentShaderID);
}

cedx::render::ShaderProgram::~ShaderProgram()
{
    stop();
    glDetachShader(_programID, _vertexShaderID);
    glDetachShader(_programID, _fragmentShaderID);
    glDeleteShader(_vertexShaderID);
    glDeleteShader(_fragmentShaderID);
    glDeleteProgram(_programID);
}

void cedx::render::ShaderProgram::validateProgram()
{
    glLinkProgram(_programID);
    glValidateProgram(_programID);
}

void cedx::render::ShaderProgram::bindAttributes(int attribNumber, const std::string &variableName)
{
    glBindAttribLocation(_programID, attribNumber, variableName.c_str());
}

void cedx::render::ShaderProgram::start()
{
    glUseProgram(_programID);
}

void cedx::render::ShaderProgram::stop()
{
    glUseProgram(0);
}

GLuint cedx::render::ShaderProgram::loadShader(const std::string &fp, int type)
{
    std::ifstream file(fp);
    std::stringstream fileStream;

    if (!file.is_open()) {
        std::cerr << "could not open file fp: " << fp << std::endl;
        exit(84);
    }
    fileStream << file.rdbuf();
    std::string content(fileStream.str());
    const GLchar *const shaderFileContent = content.c_str();

    GLuint shaderID = glCreateShader(type);
    // glShaderSource(shaderID, fileStream.str().c_str());
    glShaderSource(shaderID, 1, &shaderFileContent, NULL);
    glCompileShader(shaderID);
    GLint success = 0;
    
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &success);

        GLchar *infolog = new GLchar[success + 1];
        memset(infolog, 0, success + 1);
        glGetShaderInfoLog(shaderID, success, nullptr, infolog);
        std::cerr << infolog << std::endl;
        delete[] infolog;
        exit(84);
}
    return shaderID;
}

int cedx::render::ShaderProgram::getShaderUniformLocation(const std::string &uniName)
{
    return glGetUniformLocation(_programID, uniName.c_str());
}

void cedx::render::ShaderProgram::loadFloat(int location, float value)
{
    glUniform1f(location, value);
}

void cedx::render::ShaderProgram::loadVector3(int location, const glm::vec3 &value)
{
    glUniform3f(location, value.x, value.y, value.z);
}

void cedx::render::ShaderProgram::loadMatrix(int location, const glm::mat4 &value)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void cedx::render::ShaderProgram::loadBoolean(int location, bool value)
{
    glUniform1f(location, ((value) ? 1 : 0));
}
