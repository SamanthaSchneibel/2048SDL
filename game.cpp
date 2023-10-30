#include "game.hpp"

Game::Game()
{
    grid.spawnCell();
    grid.spawnCell();
}

Game::~Game()
{
}

void Game::display() {

    grid.display();

}

void Game::handleEvent() {

    bool badKey = true;
    while (badKey)
    {
        badKey = false;
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            if (grid.moveUp()) {
                grid.spawnCell();
            }
            break;
        case KEY_DOWN:
            if (grid.moveDown()) {
                grid.spawnCell();
            }
            break;
        case KEY_RIGHT:
            if (grid.moveRight()) {
                grid.spawnCell();
            }
            break;
        case KEY_LEFT:
            if (grid.moveLeft()) {
                grid.spawnCell();
            }
            break;
        default:
            badKey = true;
            break;
        }
    }

}