#pragma once

#include <SDL.h>

class Game 
{
public:
    Game();
    ~Game();
    void intialize();
    void setup();
    void processInput();
    void update();
    void render();
    void run();
    void destroy();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning = false;
    int millisecPreviousFrame;
};