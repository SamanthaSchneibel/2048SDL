#include "game.hpp"
#include "test.hpp"

int main() {

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