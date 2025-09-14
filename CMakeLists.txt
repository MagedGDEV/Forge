cmake_minimum_required(VERSION 4.0)

project(SDL-GameEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CPM)
CPMUsePackageLock(package-lock.cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_executable(SDL-GameEngine
    src/main.cpp
)

target_include_directories(SDL-GameEngine PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${ASSETS_DIR}"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
)

target_link_libraries(SDL-GameEngine PRIVATE 
    lua 
    sol2
    glm::glm
    imgui
    SDL2::SDL2 
    SDL2_image::SDL2_image 
    SDL2_mixer::SDL2_mixer
)