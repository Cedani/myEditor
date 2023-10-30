#include "ModelTexture.hpp"

cedx::render::ModelTexture::ModelTexture(sf::Texture &texture): _texture(texture)
{

}

cedx::render::ModelTexture::~ModelTexture()
{

}

const sf::Texture & cedx::render::ModelTexture::getTexture() const
{
    return _texture;
}