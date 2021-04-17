#ifndef GAME_H
#define GAME


class Game {
public:
	
	Game();
	~Game();


	void init(const char *title, int width, int height);
	void update(float delta);
	void render(float delta);

	void init();
	void dispose();
};



#endif GAME_H