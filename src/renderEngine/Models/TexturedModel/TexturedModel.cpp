#include "TexturedModel.hpp"

cedx::render::TexturedModel::TexturedModel(RawModel &model, ModelTexture &texture): _rawModel(model), _texture(texture)
{

}

cedx::render::TexturedModel::~TexturedModel()
{

}

const cedx::render::RawModel &cedx::render::TexturedModel::getRawModel() const
{
    return _rawModel;
}

const cedx::render::ModelTexture &cedx::render::TexturedModel::getTexture() const
{
    return _texture;
}