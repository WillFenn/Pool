cmake_minimum_required(VERSION 3.23)

project("Pool" CXX)

# build pool
add_subdirectory("src")

# build freetype
add_subdirectory("${CMAKE_SOURCE_DIR}/dependencies/freetype-2.14.3" EXCLUDE_FROM_ALL)

# build glew
add_subdirectory("${CMAKE_SOURCE_DIR}/dependencies/glew-2.3.1/build/cmake" EXCLUDE_FROM_ALL)

# build glfw
add_subdirectory("${CMAKE_SOURCE_DIR}/dependencies/glfw-3.4" EXCLUDE_FROM_ALL)

install(
    TARGETS
        "${PROJECT_NAME}"

    DESTINATION
        "."
)

install(
    DIRECTORY
        "${CMAKE_SOURCE_DIR}/res"

    DESTINATION
        "."
)