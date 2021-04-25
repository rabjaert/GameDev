#include <iostream>
#include "header/game.h"
#include "header/TextureManager.h"
#include "header/PlayerObject.h"


#include "header/ESC/Components.h"
#include "header/ESC/Vector2D.h"
#include "header/ESC/Collision.h"


SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;

/* Prøve å unngå å bruke globale variabler */
PlayerObject* mage;
PlayerObject* potion;



Manager manager;
auto& newPlayer(manager.addEntity());
auto& wall(manager.addEntity());
auto& wall1(manager.addEntity());
auto& wall2(manager.addEntity());
auto& wall3(manager.addEntity());

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
	std::cout << "SDL initialized" << std::endl;


	/* Under her kan vi ha kode for å teste ting */
	//mage = new PlayerObject(renderer, 110, 0);
	//mage->setTexture("res/textures/character/character_spritesheet.png");
	//potion = new PlayerObject(renderer, 0, 0);
	//potion->setTexture("res/textures/gui/gui_sheet.png");

	newPlayer.addComponent<TransformComponent>(2);
	newPlayer.addComponent<SpriteComponent>("res/textures/character/character_spritesheet.png");
	newPlayer.addComponent<KeyboardController>();
	newPlayer.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 300, 1);
	wall.addComponent<SpriteComponent>("res/textures/tileset/flora.png");
	wall.addComponent<ColliderComponent>("wall");

	wall2.addComponent<TransformComponent>(700.0f, 300.0f, 300, 300, 1);
	wall2.addComponent<SpriteComponent>("res/textures/tileset/flora.png");
	wall2.addComponent<ColliderComponent>("wall2");

	

}

void Game::handleEvents()
{
	
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT) {
			running = false;
		}

		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				running = false;
			}
			
		}
	}
}

void Game::update()
{
	//mage->update();
	//potion->update();
	manager.refresh();
	manager.update();

	if (Collision::AABB(newPlayer.getComponent<ColliderComponent>().collider,
		wall.getComponent<ColliderComponent>().collider))
	{
		
		std::cout << "Wall hit!" << std::endl;
	}

	if (Collision::AABB(newPlayer.getComponent<ColliderComponent>().collider,
		wall2.getComponent<ColliderComponent>().collider))
	{

		std::cout << "Wall hit!" << std::endl;
	}
	
	
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
	SDL_RenderClear(renderer);

	//mage->render();
	//potion->render();
	manager.render();


	SDL_RenderPresent(renderer);
}


void Game::dispose()
{
	delete mage;
	delete potion;

	IMG_Quit();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}