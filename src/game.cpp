#include "game.h"

#include <SDL_image.h>

#include <glm/vec2.hpp>

#include "logger.h"

constexpr int FPS = 60;
constexpr int MILLISECOND_PER_FRAME = 1000/FPS;

Game::Game()
{
    Logger::INFO("Game intialized");
}

Game::~Game()
{
    Logger::INFO("Game destroyed");
}

void Game::intialize()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        Logger::ERR("Error Intializing SDL");

    window = SDL_CreateWindow(
        nullptr,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_BORDERLESS
    );
    if (!window)
        Logger::ERR("Error Creating SDL window");

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (!renderer)
        Logger::ERR("Error Creating SDL renderer");

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);    

    isRunning = true;
}

glm::vec2 playerPosition, playerVelocity;

void Game::setup()
{
    playerPosition = {60, 60};
    playerVelocity = {100, 0};
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
    int timeToWait = MILLISECOND_PER_FRAME - (SDL_GetTicks() - millisecPreviousFrame);
    if (timeToWait > 0)
        SDL_Delay(timeToWait);

    // Allow changes to be /sec not /frame
    double deltaTime = (SDL_GetTicks() - millisecPreviousFrame) / 1000.0;    

    millisecPreviousFrame = SDL_GetTicks();

    playerPosition.x += playerVelocity.x * deltaTime;
    playerPosition.y += playerVelocity.y * deltaTime;
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