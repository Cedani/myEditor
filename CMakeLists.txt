cmake_minimum_required(VERSION 3.20)

project(CedX)

set(CMAKE_CXX_STANDARD 17)


include(C:/Users/Cedani/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(SIMPLE_VERT ${CMAKE_SOURCE_DIR}/src/renderEngine/Shaders/simple.vert)
set(SIMPLE_FRAG ${CMAKE_SOURCE_DIR}/src/renderEngine/Shaders/simple.frag)
set(RES_IMAGES ${CMAKE_SOURCE_DIR}/Resources/Images)

configure_file(${CMAKE_SOURCE_DIR}/src/RenderEngine/utilsRender.h.in ${CMAKE_SOURCE_DIR}/src/RenderEngine/utilsRender.h)
# find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(glad REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
string(REPLACE "-O2" "-O0" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
string(REPLACE "-O2" "-O0" CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")


include_directories(${CMAKE_SOURCE_DIR}/src/Math/)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Camera/)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Loader/)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Display/)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Renderer/)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Entity/)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Models/RawModel/)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Shaders/StaticShader)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Shaders/ShaderProgram)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Models/TexturedModel/)
include_directories(${CMAKE_SOURCE_DIR}/src/renderEngine/Texture/ModelTexture/)

set(SRC
    ${CMAKE_SOURCE_DIR}/src/Math/libMath.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Display/Display.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Camera/Camera.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Loader/Loader.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Models/RawModel/RawModel.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Models/TexturedModel/TexturedModel.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Renderer/Renderer.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Shaders/ShaderProgram/ShaderProgram.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Shaders/StaticShader/StaticShader.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Texture/ModelTexture/ModelTexture.cpp
    ${CMAKE_SOURCE_DIR}/src/renderEngine/Entity/Entity.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

add_executable(CedX ${SRC})
target_link_libraries(CedX PRIVATE sfml-window sfml-graphics sfml-system glad::glad glm::glm)