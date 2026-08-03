add_executable("${PROJECT_NAME}")

target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_20)

target_sources("${PROJECT_NAME}"
    PRIVATE
        "${CMAKE_SOURCE_DIR}/src/game/Ball.cpp"
        "${CMAKE_SOURCE_DIR}/src/game/Cue.cpp"
        "${CMAKE_SOURCE_DIR}/src/game/Game.cpp"
        "${CMAKE_SOURCE_DIR}/src/game/Side.cpp"
        "${CMAKE_SOURCE_DIR}/src/physics/physics.cpp"
        "${CMAKE_SOURCE_DIR}/src/rendering/GameObject.cpp"
        "${CMAKE_SOURCE_DIR}/src/rendering/Line.cpp"
        "${CMAKE_SOURCE_DIR}/src/rendering/Shader.cpp"
        "${CMAKE_SOURCE_DIR}/src/rendering/stb_image.cpp"
        "${CMAKE_SOURCE_DIR}/src/rendering/Texture.cpp"
        "${CMAKE_SOURCE_DIR}/src/rendering/Window.cpp"
        "${CMAKE_SOURCE_DIR}/src/ui/Character.cpp"
        "${CMAKE_SOURCE_DIR}/src/ui/Menu.cpp"
        "${CMAKE_SOURCE_DIR}/src/ui/MenuOption.cpp"
        "${CMAKE_SOURCE_DIR}/src/ui/Panel.cpp"
        "${CMAKE_SOURCE_DIR}/src/ui/TextLabel.cpp"
        "${CMAKE_SOURCE_DIR}/src/utilities/Input.cpp"
        "${CMAKE_SOURCE_DIR}/src/utilities/PoolColors.cpp"
        "${CMAKE_SOURCE_DIR}/src/utilities/PoolMath.cpp"
        "${CMAKE_SOURCE_DIR}/src/Pool.cpp"

    PRIVATE
        FILE_SET HEADERS
        BASE_DIRS
            "${CMAKE_SOURCE_DIR}/src/game"
            "${CMAKE_SOURCE_DIR}/src/physics"
            "${CMAKE_SOURCE_DIR}/src/rendering"
            "${CMAKE_SOURCE_DIR}/src/ui"
            "${CMAKE_SOURCE_DIR}/src/utilities"
        FILES
            "${CMAKE_SOURCE_DIR}/src/game/Ball.h"
            "${CMAKE_SOURCE_DIR}/src/game/Cue.h"
            "${CMAKE_SOURCE_DIR}/src/game/Game.h"
            "${CMAKE_SOURCE_DIR}/src/game/Player.h"
            "${CMAKE_SOURCE_DIR}/src/game/Side.h"
            "${CMAKE_SOURCE_DIR}/src/physics/physics.h"
            "${CMAKE_SOURCE_DIR}/src/rendering/GameObject.h"
            "${CMAKE_SOURCE_DIR}/src/rendering/Line.h"
            "${CMAKE_SOURCE_DIR}/src/rendering/Shader.h"
            "${CMAKE_SOURCE_DIR}/src/rendering/Texture.h"
            "${CMAKE_SOURCE_DIR}/src/rendering/Window.h"
            "${CMAKE_SOURCE_DIR}/src/ui/Character.h"
            "${CMAKE_SOURCE_DIR}/src/ui/Font.h"
            "${CMAKE_SOURCE_DIR}/src/ui/FontSize.h"
            "${CMAKE_SOURCE_DIR}/src/ui/Menu.h"
            "${CMAKE_SOURCE_DIR}/src/ui/MenuOption.h"
            "${CMAKE_SOURCE_DIR}/src/ui/Panel.h"
            "${CMAKE_SOURCE_DIR}/src/ui/TextLabel.h"
            "${CMAKE_SOURCE_DIR}/src/utilities/Input.h"
            "${CMAKE_SOURCE_DIR}/src/utilities/PoolColors.h"
            "${CMAKE_SOURCE_DIR}/src/utilities/PoolMath.h"
)

# link freetype
target_link_libraries("${PROJECT_NAME}" PRIVATE "freetype")

# link glew
target_link_libraries("${PROJECT_NAME}" PRIVATE "glew_s")

target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_SOURCE_DIR}/dependencies/glew-2.3.1/include")

# link glfw
target_link_libraries("${PROJECT_NAME}" PRIVATE "glfw" "${GLFW_LIBRARIES}")

target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_SOURCE_DIR}/dependencies/glfw-3.4/include")

# link glm
target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_SOURCE_DIR}/dependencies/glm")

# link stb_image
add_library("stb_image" INTERFACE)

target_sources("stb_image"
    INTERFACE
        FILE_SET HEADERS
        BASE_DIRS
            "${CMAKE_SOURCE_DIR}/dependencies/stb_image"
        FILES
            "${CMAKE_SOURCE_DIR}/dependencies/stb_image/stb_image.h"
)

target_link_libraries("${PROJECT_NAME}" PRIVATE "stb_image")