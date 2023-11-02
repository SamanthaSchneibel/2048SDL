#include "window.hpp"

Window::Window()
{
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Sub system init" << std::endl;

		window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);
		if (window)
			std::cout << "Window init" << std::endl;

		ren = SDL_CreateRenderer(window, -1, 0);
		if (ren)
		{
			std::cout << "Renderer init" << std::endl;
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		}
	}
	isRunning = true;

	grid.spawnCell();
	grid.spawnCell();

}

Window::~Window()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::event() { //Gestion des évènements

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

	bool badKey = true;
	while (badKey)
	{
		badKey = false;
		int c = 0;
		switch ((c = _getch()))
		{
		case KEY_UP:
			if (grid.moveUp()) {
				grid.spawnCell();
			}
			break;
		case KEY_DOWN:
			if (grid.moveDown()) {
				grid.spawnCell();
			}
			break;
		case KEY_RIGHT:
			if (grid.moveRight()) {
				grid.spawnCell();
			}
			break;
		case KEY_LEFT:
			if (grid.moveLeft()) {
				grid.spawnCell();
			}
			break;
		default:
			badKey = true;
			break;
		}
	}

}

void Window::update() { //Mettre à jour les variables selon les évènements



}

void Window::display() { //Afficher le rendu

	SDL_RenderClear(ren);

	grid.display();

	//Afficher ici

	SDL_RenderPresent(ren);

}