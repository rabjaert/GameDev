#include <iostream>
#include "header/game.h"
#include "header/TextureManager.h"
#include "header/PlayerObject.h"



SDL_Renderer* Game::renderer = nullptr;
SDL_Texture* swordman;
SDL_Rect srcR, destR;
PlayerObject* mage;
PlayerObject* potion;

Game::Game() {}


Game::~Game() {}


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
	/*
	SDL_Surface* surface = IMG_Load("res/textures/character/character_spritesheet.png");
	swordman = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);*/

	//swordman = TextureManager::LoadTexture("res/textures/character/character_spritesheet.png", renderer);
	//swordman = TextureManager::LoadTexture(TextureManager::GetImages("character", "character_spritesheet.png"), renderer);
	mage = new PlayerObject("res/textures/character/character_spritesheet.png", renderer, 110, 0);
	potion = new PlayerObject("res/textures/gui/gui_sheet.png", renderer, 0, 0);

	std::cout << "SDL initialized" << std::endl;

	/*
	destR.h = 64;
	destR.w = 64;

	destR.x = 100;
	destR.y = 100;


	srcR.h = 30;
	srcR.w = 15;
	*/
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				running = false;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_W) {
				
				mage->setY(-20);
				
			}
			if(event.key.keysym.scancode == SDL_SCANCODE_S) {
				
					mage->setY(+400);
				
				
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_A) {
				
					mage->setX(-20);
				
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_D) {
				
					mage->setX(+400);
				
			}

		}

	}
}

void Game::update()
{
	mage->Update();
	potion->Update();

}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, swordman, &srcR, &destR);
	potion->RenderObject();
	mage->RenderObject();
	
	SDL_RenderPresent(renderer);
}


void Game::dispose()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}