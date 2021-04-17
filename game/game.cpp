#include <iostream>
#include "game.h"

SDL_Renderer *Game::renderer = nullptr;


Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int width, int height)
{

        std::cout << "Initializing SDL" << std::endl;

        /* Initialize defaults, Video and Audio */
        if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)) {
                std::cout << "Could not initialize SDL\n" << SDL_GetError() << std::endl;
                exit(-1);
        }

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        renderer = SDL_CreateRenderer(window, 0, 0);
        running = true;

        std::cout << "SDL initialized" << std::endl;
}

void Game::handleEvents()
{
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
                if (event.type == SDL_KEYDOWN) {
                        if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                                running = false;
                        }
                }
        }
}

void Game::update()
{

}

void Game::render()
{
        SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
}


void Game::dispose()
{
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
}