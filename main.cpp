#include "window.hpp"
#include "test.hpp"

int main(int argc, char* argv[]) { 

	srand(static_cast<unsigned int>(time(0)));

	Window game;
	game.display();

	while (game.running()) {
		game.event();
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