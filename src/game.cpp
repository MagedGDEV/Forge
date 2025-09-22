#include "game.h"

#include <iostream>

#include <SDL_image.h>

#include <glm/vec2.hpp>

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

glm::vec2 playerPosition, playerVelocity;

void Game::setup()
{
    playerPosition = {60, 60};
    playerVelocity = {1, 0};
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
    playerPosition.x += playerVelocity.x;
    playerPosition.y += playerVelocity.y;
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderClear(renderer);

    SDL_Surface* surface = IMG_Load("assets/images/tank-tiger-right.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect rect {
        static_cast<int>(playerPosition.x),
        static_cast<int>(playerPosition.y),
        32,
        32
    };
    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    SDL_DestroyTexture(texture);

    SDL_RenderPresent(renderer);
}

void Game::run()
{
    setup();
    while (isRunning) 
    {
        processInput();
        update();
        render();
    }
}

void Game::destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}