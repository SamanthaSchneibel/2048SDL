#include "window.hpp"
#include "test.hpp"

int main(int argc, char* argv[]) { 

	srand(static_cast<unsigned int>(time(0)));

	/*
	Test test;

	while (test.running()) {
		test.test();
	}
	*/

	SDL_Window* window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);
	SDL_Renderer* ren = SDL_CreateRenderer(window, -1, 0);

	bool isRunning = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		printf("sub system init");

		if (window)
			printf("\n Window init");

		if (ren)
		{
			printf("\n Renderer init");
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
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

		SDL_RenderPresent(ren);
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();

	Window game;
	game.display();

	while (game.running()) {
		game.handleEvent();
		game.display();
	}

	std::cout << "LOOOSERRR" << std::endl;

	/*
	Window game;
	game.display();

	while (game.running()) {
		//EVENT
		game.event();
		
		//UPDATE

		if (game.isDefeat())
		{
			std::cout << "LOOOSERRR" << std::endl;
		}

		//DISPLAY
		game.display();
	}
	*/

	return 0;
}