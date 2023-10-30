#pragma once
#include <SFML/Graphics/Texture.hpp>

namespace cedx {
    namespace render {
        class ModelTexture {
            public:
                ModelTexture(sf::Texture &);
                ~ModelTexture();

                const sf::Texture &getTexture() const;
            private:
                sf::Texture &_texture;
        };
    }
}