#pragma once
#include "RawModel.hpp"
#include "ModelTexture.hpp"

namespace cedx {
    namespace render {
        class TexturedModel {
            public:
                TexturedModel(RawModel &model, ModelTexture &texture);
                ~TexturedModel();

                const RawModel &getRawModel() const;
                const ModelTexture &getTexture() const;

            private:
                RawModel &_rawModel;
                ModelTexture &_texture;

        };
    }
}