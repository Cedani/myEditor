#version 450 core

in vec3 position;
in vec2 textureCoords;

// out vec3 colour;

out vec2 frag_texture_coord;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main(void)
{
    gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4(position, 1.0);
    frag_texture_coord = textureCoords;
}