
#define SDL_MAIN_HANDLED

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <glm/glm.hpp>

#include <sol/sol.hpp>

#include <imgui.h>

int main () 
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);

    std::cout << "Hello World\n";

    glm::vec2 velocity = glm::vec2(5.0, -2.5);
    velocity = glm::normalize(velocity);

    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('Hello from Lua via sol2!')");
    
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}