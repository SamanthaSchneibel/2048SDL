#include "grid.hpp"

class Game
{
public:
	Game();
	~Game();

	void display();

	void handleEvent();

	bool running() { return !grid.isDefeat(); };

private:

	Grid grid;

};