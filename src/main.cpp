#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

int main () 
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    std::cout << "Hello World\n";
    
    IMG_Quit();
    SDL_Quit();
    return 0;
}