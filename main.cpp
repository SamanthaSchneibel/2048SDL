#include "game.hpp"
#include "test.hpp"
#include "SDL.h"
#include "SDL_image.h"

int main(int argc, char* argv[]) { 

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