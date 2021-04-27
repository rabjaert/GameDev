#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>


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

	static SDL_Event event;

	inline bool isRunning() { return running; }


	/* framerate */

	static int getStaticFramerate()  { return framerate; }
	static int getStaticFramerateTarget() { return framerateTarget; }

	inline int getFramerate() const { return framerate; }
	void setFramerate(const int fps) 
	{ 
		framerate = fps; 
	};
	/* framerate target */
	inline int getFramerateTarget() const { return framerateTarget; }
	void setFramerateTarget(const int fps) { framerateTarget = fps; }

private:
	bool running = false;
	SDL_Window* window = nullptr;

	int static framerate; // the actual rendered FPS
	int static framerateTarget; // the FPS you want to achieve

};



#endif GAME_H