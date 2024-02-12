#pragma once

#include <SFML/Window.hpp>
#include <memory>
#include "Renderer.hpp"
#include "Loader.hpp"
#include "StaticShader.hpp"
#include "ModelTexture.hpp"
#include "TexturedModel.hpp"

namespace cedx {
    namespace render {
        class Display {
            public:
                Display(int w = 800, int h=600, bool fscrn = false, const std::string &title = "OpenGL window");
                ~Display();

                void run();
                void update();
                void close();


                // static Display createNewDisplay();

            private:
                bool _running;
                sf::Window _window;
                sf::Event _event;
                Loader _loader;
                std::unique_ptr<StaticShader> _shader;
                std::unique_ptr<Renderer> _render;
        };
    }
}