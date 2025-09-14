#include <iostream>
#include <SDL.h>
#include <glm/glm.hpp>
#include <sol/sol.hpp>
#include <imgui.h>

int main () 
{

    SDL_Init(SDL_INIT_VIDEO);
    std::cout << "Hello World!" << std::endl;

    glm::vec2 velocity = glm::vec2(5.0, -2.5);
    velocity = glm::normalize(velocity);

    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('Hello from Lua via sol2!')");
    
    SDL_Quit();
    return 0;
}