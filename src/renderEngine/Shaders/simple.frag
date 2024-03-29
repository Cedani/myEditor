#version 450 core

in vec2 frag_texture_coord;

out vec4 out_Color;

uniform sampler2D textureSampler;

void main(void)
{
    out_Color = texture(textureSampler, frag_texture_coord);
}