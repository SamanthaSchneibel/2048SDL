#include "window.hpp"
#include "SDL.h"
#include "SDL_image.h"

Window::Window()
{
}

Window::~Window()
{

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();

}

