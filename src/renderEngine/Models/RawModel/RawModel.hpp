#pragma once


namespace cedx {
    namespace render {
        class RawModel {
            public:
                RawModel(int vaoID, int vertexCount);
                ~RawModel();

                int getVao() const;
                int getVertexCount() const;

            private:
                int _vaoID;
                int _vertexCount;
        };
    }
}