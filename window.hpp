#pragma once
#include "grid.hpp"
#include "SDL.h"

class Window
{

public:

	Window();
	~Window();

	void display();
	void handleEvent();
	bool running() { return !grid.isDefeat(); };

	/*
	void event();
	void update();
	void display();
	bool running() { return isRunning; };

	static SDL_Renderer* pRenderer;
	*/

private:

	/*
	SDL_Window* pWindow;

	bool isRunning = false;
	*/

	Grid grid;

};