cmake_minimum_required(VERSION 4.0)

project(Forge LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (WIN32)
    set(SDL2_DLLS
        "$ENV{SDL2_PATH}/SDL2/lib/x64/SDL2.dll"
        "$ENV{SDL2_PATH}/SDL2_image/lib/x64/SDL2_image.dll"
        "$ENV{SDL2_PATH}/SDL2_ttf/lib/x64/SDL2_ttf.dll"
        "$ENV{SDL2_PATH}/SDL2_mixer/lib/x64/SDL2_mixer.dll"
    )
endif()

set(ASSETS_DIR
    "${CMAKE_SOURCE_DIR}/assets"
)

list(APPEND CMAKE_MODULE_PATH 
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake
)

if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH
        "$ENV{SDL2_PATH}/SDL2/cmake"
        "$ENV{SDL2_PATH}/SDL2_image/cmake"
        "$ENV{SDL2_PATH}/SDL2_ttf/cmake"
        "$ENV{SDL2_PATH}/SDL2_mixer/cmake"
    )
elseif(APPLE)
    list(APPEND CMAKE_PREFIX_PATH
        "$ENV{SDL2_PATH}/SDL2.framework/Versions/A/Resources/CMake"
        "$ENV{SDL2_PATH}/SDL2_image.framework/Versions/A/Resources/CMake"
        "$ENV{SDL2_PATH}/SDL2_mixer.framework/Versions/A/Resources/CMake"
        "$ENV{SDL2_PATH}/SDL2_ttf.framework/Versions/A/Resources/CMake"
    )
endif()

include(CPM)
CPMUsePackageLock(package-lock.cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(Forge
    src/main.cpp
    src/game.cpp
    src/logger.cpp
)

target_include_directories(Forge PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

if (WIN32)
    foreach(DLL ${SDL2_DLLS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${DLL}" 
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
        )
    endforeach()
endif()

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${ASSETS_DIR}"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
)

target_link_libraries(Forge PRIVATE 
    SDL2::SDL2 
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf 
    SDL2_mixer::SDL2_mixer
    imgui
    glm
    sol2
    lua
)