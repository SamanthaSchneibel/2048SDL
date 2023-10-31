#include "window.hpp"
#include "SDL.h"
#include "SDL_image.h"

Window::Window()
{
	window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);
	ren = SDL_CreateRenderer(window, -1, 0);

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Sub system init" << std::endl;

		if (window)
			std::cout << "Window init" << std::endl;

		if (ren)
		{
			std::cout << "Renderer init" << std::endl;
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
		}
	}
	isRunning = true;
}

Window::~Window()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::Event() { //Gestion des évènements

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

}

void Window::Update() { //Mettre à jour les variables selon les évènements



}

void Window::Display() { //Afficher le rendu

	SDL_RenderClear(ren);

	//Afficher ici

	SDL_RenderPresent(ren);

}