#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>

class Window
{
public:
	Window();
	~Window();

	void Event();
	void Update();
	void Display();

private:

	SDL_Window* window;
	SDL_Renderer* ren;

	bool isRunning = false;

};