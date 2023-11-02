#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "cell.hpp"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


class Grid
{
public:
	Grid();
	// Grid(Cell config[4][4]);
	~Grid();

	void display();

	void handleEvent();

	bool moveRight();
	bool moveLeft();
	bool moveUp();
	bool moveDown();

	void spawnCell();

	bool isDefeat();

	// bool compare(Cell config[4][4]);

private:

	Cell grid[4][4];

};