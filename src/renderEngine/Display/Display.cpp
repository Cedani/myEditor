#include "Display.hpp"
#include <glm/gtx/string_cast.hpp>

cedx::render::Display::Display(int w, int h, bool fscrn, const std::string &title)
{
    sf::ContextSettings settings;

    settings.depthBits = 32;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 2;
    settings.majorVersion = 4;
    settings.minorVersion = 6;
    // _window.setFramerateLimit(30);
    _window.create(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, settings);
    int version = gladLoadGL();
    if (version == 0) {
        std::cerr << "failed opengl" << std::endl;
        exit (84);
    }
}

cedx::render::Display::~Display()
{

}

void cedx::render::Display::run()
{
    _window.setActive(true);
    _running = true;
    _shader = std::make_unique<StaticShader>();
    _render = std::make_unique<Renderer>(*_shader, _window.getSize().x, _window.getSize().y);

    // std::vector<GLfloat> vertices = {
    //     -0.5f, 0.5f, 0.f,
    //     -0.5f, -0.5f, 0.f,
    //     0.5f, -0.5f, 0.f,
    //     0.5f, 0.5f, 0.f,
    // };

    std::vector<GLfloat> vertices = {
        -0.5f,0.5f,-0.5f,	
		-0.5f,-0.5f,-0.5f,	
		0.5f,-0.5f,-0.5f,	
		0.5f,0.5f,-0.5f,		
				
		-0.5f,0.5f,0.5f,	
		-0.5f,-0.5f,0.5f,	
		0.5f,-0.5f,0.5f,	
		0.5f,0.5f,0.5f,
				
		0.5f,0.5f,-0.5f,	
		0.5f,-0.5f,-0.5f,	
		0.5f,-0.5f,0.5f,	
		0.5f,0.5f,0.5f,
				
		-0.5f,0.5f,-0.5f,	
		-0.5f,-0.5f,-0.5f,	
		-0.5f,-0.5f,0.5f,	
		-0.5f,0.5f,0.5f,
				
		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,
				
		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f
    };

    // std::vector<GLuint> indices = {
    //     0, 1, 3,
    //     3, 1, 2
    // };

    std::vector<GLuint> indices = {
        0,1,3,	
		3,1,2,	
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,	
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22
    };

    // std::vector<GLfloat> textureCoords = {
    //     0,0,
    //     0,1,
    //     1,1,
    //     1,0,
    // };

    std::vector<GLfloat> textureCoords = {
        0,0,
		0,1,
		1,1,
		1,0,			
		0,0,
		0,1,
		1,1,
		1,0,			
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0
    };

    RawModel model = _loader.loadToVAO(vertices, textureCoords, indices);
    ModelTexture texture(_loader.loadTexture(RES_IMAGES + std::string("/testTexture.png")));
    TexturedModel texturedModel(model, texture);

    Entity entity(texturedModel, glm::vec3(0, 0, -2.f), glm::vec3(0,0,0), 1);
    Camera camera;

    while (_running) {
        // entity.changePosition(0, 0, 0);
        entity.changeRotation(0.1f, 0.1f, 0);
        _render->prepare();
        _shader->start();
        
        while(_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _running = false;
            } else if (_event.type == sf::Event::Resized) {
                glViewport(0, 0, _event.size.width, _event.size.height);
            } else {
                camera.move(_event);
            }
        }
        _shader->loadViewMatrix(camera);
        std::cerr << glm::to_string(camera.getPosition()) << std::endl;
        _render->render(entity, *_shader);
        _shader->stop();
        // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        _window.display();
    }
}

void cedx::render::Display::update()
{

}

void cedx::render::Display::close()
{
    
}
