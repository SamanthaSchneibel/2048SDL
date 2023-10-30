#include "game.hpp"
#include "test.hpp"
#include "SDL.h"
#include "SDL_image.h"

int main(int argc, char* argv[]) {

	const char* title = "2048";

	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);
	SDL_Renderer* ren = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface* tmpSur = IMG_Load("img/player.png");
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSur);

	SDL_FreeSurface(tmpSur);
	SDL_Rect src, dest;
	src.h = src.w = 32;
	src.x = src.y = 0;
	dest.x = dest.y = 400;
	dest.w = src.w * 2;
	dest.h = src.h * 2;

	bool isRunning = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		printf("sub system init");

		if (window)
			printf("\n Window init");

		if (ren)
		{
			printf("\n Renderer init \n");
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
		}

		isRunning = true;

	}
	else
		isRunning = false;

	while (isRunning)
	{
		// Gestion des évènements
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
		}

		// Mettre à jour les variables selon les évènements

		// Afficher le rendu
		SDL_RenderClear(ren);
		// Afficher ici
		SDL_RenderCopy(ren, tex, &src, &dest);

		SDL_RenderPresent(ren);
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();

	
	
	
	srand(static_cast<unsigned int>(time(0)));

	Game game;
	game.display();

	while (game.running()) {
		game.handleEvent();
		game.display();
	}

	std::cout << "LOOOSERRR" << std::endl;

	/*
	Test test;

	while (test.running()) {
		test.test();
	}
	*/

	return 0;
}