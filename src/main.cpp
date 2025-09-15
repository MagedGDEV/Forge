#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

#include <glm/glm.hpp>

#include <sol/sol.hpp>

#include <imgui.h>

int main () 
{
    std::cout << "Hello World!" << std::endl;
    
    SDL_Init(SDL_INIT_VIDEO);

    glm::vec2 velocity = glm::vec2(5.0, -2.5);
    velocity = glm::normalize(velocity);

    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('Hello from Lua via sol2!')");
    
    SDL_Quit();
    return 0;
}