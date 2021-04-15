#include <stdio.h>
#include <SDL.h>

int main(int argc, char **argv)
{
	if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)) {
		puts("error");
	}
	printf("%s\n", "Hello world");
	return 0;
}