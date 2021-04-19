#ifndef GAME_H
#define GAME

#include <SDL.h>

class Game {
public:

	Game();
	~Game();

	void init(const char* title, int width, int height);
	void handleEvents();
	void update();
	void render();
	void dispose();

	static SDL_Renderer* renderer;

	inline bool isRunning() { return running; }
	int fps;

private:
	bool running = false;
	SDL_Window* window;

};



#endif GAME_H