#include <iostream>
#include <SDL.h>
#include "header/game.h"


int main(int argc, char* argv[]) {
	Game game;
	

	game.init("spill", 1024, 768);
	game.setFramerateTarget(60);

	
	float delta = 0;
	float secondsloop = 0;
	auto sleep = [&]{ return 1000.0f / game.getFramerateTarget(); };

	const uint64_t frequency = SDL_GetPerformanceFrequency();
	uint64_t timenow = SDL_GetPerformanceCounter();

	while (game.isRunning()) {
		
		uint64_t last = timenow;
		do
		{
			timenow = SDL_GetPerformanceCounter(); // bad?
			delta = ((timenow - last) * 1000 / (float)frequency);
		} while (delta < sleep()); // wait for the target fps
		// use sleep?
		secondsloop += delta;

		game.handleEvents();
		game.update();
		game.render();

		if (secondsloop >= 1000.0f)
		{
			game.setFramerate((int)(1000.0f / delta) + 1);
			std::cout << "FPS: " << game.getFramerate() << std::endl;
			secondsloop = 0;
		}	
		

	}

	game.dispose();
	
	return 0;
}
