#define SDL_MAIN_HANDLED

#include "game.h"

int main () 
{
    Game game;
    
    game.intialize();
    game.run();
    game.destroy();
    
    return 0;
}