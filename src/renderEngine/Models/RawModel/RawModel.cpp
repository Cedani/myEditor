#include "RawModel.hpp"

cedx::render::RawModel::RawModel(int vaoID, int vertexCount): _vaoID(vaoID), _vertexCount(vertexCount)
{
}

cedx::render::RawModel::~RawModel()
{

}

int cedx::render::RawModel::getVao() const
{
    return _vaoID;
}

int cedx::render::RawModel::getVertexCount() const
{
    return _vertexCount;
}