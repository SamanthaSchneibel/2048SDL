#include "window.hpp"
#include "test.hpp"

int main(int argc, char* argv[]) { 

	srand(static_cast<unsigned int>(time(0)));

	Window game;
	game.display();

	while (game.running()) {
		//EVENT
		game.event();
		
		//UPDATE
		/*
		if (game.isDefeat())
		{
			std::cout << "LOOOSERRR" << std::endl;
		}*/


		//DISPLAY
		game.display();
	}

	/*
	Test test;

	while (test.running()) {
		test.test();
	}
	*/

	return 0;
}