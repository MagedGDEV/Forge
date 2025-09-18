CPMAddPackage(
    NAME SDL2
    GITHUB_REPOSITORY libsdl-org/SDL
    GIT_TAG release-2.32.10
    OPTIONS "SDL_SHARED ON"
)

CPMAddPackage(
    NAME SDL2_image
    GITHUB_REPOSITORY libsdl-org/SDL_image
    GIT_TAG release-2.8.8
    OPTIONS "SDL2IMAGE_SHARED ON"
)

CPMAddPackage(
    NAME lua
    GITHUB_REPOSITORY lua/lua
    GIT_TAG v5.4.8
)
include(cmake/lua.cmake)

CPMAddPackage(
    NAME sol2
    GITHUB_REPOSITORY ThePhD/sol2
    GIT_TAG c1f95a773c6f8f4fde8ca3efe872e7286afe4444
)

CPMAddPackage(
    NAME glm
    GITHUB_REPOSITORY g-truc/glm
    GIT_TAG 1.0.1
)

CPMAddPackage(
    NAME imgui
    GITHUB_REPOSITORY ocornut/imgui
    GIT_TAG v1.92.2b
)
include(cmake/imgui.cmake)