#include "game.h"

#include <iostream>

Game::Game()
{
    std::cout << "Game intialized\n";
}

Game::~Game()
{
    std::cout << "Game destroyed\n";
}

void Game::intialize()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cerr << "Error Intializing SDL" << std::endl;

    window = SDL_CreateWindow(
        nullptr,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_BORDERLESS
    );
    if (!window)
        std::cerr << "Error Creating SDL window" << std::endl;

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (!renderer)
        std::cerr << "Error Creating SDL renderer" << std::endl;

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);    

    isRunning = true;
}

void Game::setup()
{

}

void Game::run()
{
    while (isRunning) 
    {
        processInput();
        update();
        render();
    }
}

void Game::processInput()
{
    SDL_Event sdEvent;
    while(SDL_PollEvent(&sdEvent))
    {
        switch (sdEvent.type) 
        {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if (sdEvent.key.keysym.sym == SDLK_ESCAPE) 
                    isRunning = false;
                break;
        }
    }
}

void Game::update()
{

}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderClear(renderer);

    SDL_Rect rect {30, 40, 100, 200};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

void Game::destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}