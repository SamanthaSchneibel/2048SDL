#include "window.hpp"

Window::Window()
{
	grid.spawnCell();
	grid.spawnCell();
}

Window::~Window()
{
}

void Window::display() {

	grid.display();

}

void Window::handleEvent() {

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

/*
SDL_Renderer* Window::pRenderer;

Window::Window()
{
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Sub system init" << std::endl;

		pWindow = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);
		if (pWindow)
			std::cout << "Window init" << std::endl;

		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
		if (pRenderer)
		{
			std::cout << "Renderer init" << std::endl;
			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
		}
	}
	isRunning = true;

	grid.spawnCell();
	grid.spawnCell();
}

Window::~Window()
{
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
}

void Window::event() { //Gestion des évènements

	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
		}
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

	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(pRenderer);

	grid.display();

	//Afficher ici

	SDL_RenderPresent(pRenderer);

}
*/