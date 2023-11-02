#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "grid.hpp"
#include "SDL.h"
#include "SDL_image.h"

class Window
{
public:
	Window();
	~Window();

	void event();
	void update();
	void display();
	bool running() { return !grid.isDefeat(); };

private:

	SDL_Window* window;
	SDL_Renderer* ren;

	bool isRunning = false;

	Grid grid;

};