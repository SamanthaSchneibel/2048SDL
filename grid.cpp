#include "grid.hpp"

Grid::Grid()
{
    /*
    SDL_Surface* surfaces[11];

    surfaces[0] = SDL_LoadBMP("img/2.bmp");
    surfaces[1] = SDL_LoadBMP("img/4.bmp");
    surfaces[2] = SDL_LoadBMP("img/8.bmp");
    surfaces[3] = SDL_LoadBMP("img/16.bmp");
    surfaces[4] = SDL_LoadBMP("img/32.bmp");
    surfaces[5] = SDL_LoadBMP("img/64.bmp");
    surfaces[6] = SDL_LoadBMP("img/128.bmp");
    surfaces[7] = SDL_LoadBMP("img/256.bmp");
    surfaces[8] = SDL_LoadBMP("img/512.bmp");
    surfaces[9] = SDL_LoadBMP("img/1024.bmp");
    surfaces[10] = SDL_LoadBMP("img/2048.bmp");

    textures.resize(11);
    for (int i = 0; i < 12; ++i) 
    {
        if (surfaces[i] == NULL)
        {
            std::cout << "Error SDL_LoadBMP :" << SDL_GetError();
            exit(1);
        }

        textures[ i ] = SDL_CreateTextureFromSurface(Window::pRenderer, surfaces[i]);
        
        if (textures[i] == NULL)
        {
            std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
            exit(1);
        }
        
        SDL_FreeSurface(surfaces[i]);
    }

    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 4; ++j)
        {
            grid[i][j].setTextures(&textures);
        }
    }
    */

}

/*
Grid::Grid(int config[4][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            grid[i][j].setValue(config[i][j]);
        }
    }
}
*/

Grid::~Grid()
{
}

void Grid::display() 
{

    system("cls");

    std::cout << "-------------------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "|";
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].getValue() > 512)
                std::cout << grid[i][j].getValue() << " |";
            else if (grid[i][j].getValue() > 64)
                std::cout << grid[i][j].getValue() << "  |";
            else if (grid[i][j].getValue() > 8)
                std::cout << grid[i][j].getValue() << "   |";
            else if (grid[i][j].getValue() == 0)
                std::cout << "     |";
            else if (grid[i][j].getValue() < 16)
                std::cout << grid[i][j].getValue() << "    |";
        }
        std::cout << std::endl << "-------------------------" << std::endl;
    }

    /*
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grid[i][j].draw();
        }
    }
    */

}

bool Grid::moveRight() {

    bool move = false;

    for (int iColumn = 0; iColumn < 4; iColumn++) {
        for (int iFullCell1 = 3; iFullCell1 >= 0; iFullCell1--) {
            if (grid[iColumn][iFullCell1].isEmpty()) {
                continue;
            }

            for (int iFullCell2 = iFullCell1 - 1; iFullCell2 >= 0; iFullCell2--) {
                if (grid[iColumn][iFullCell2].isEmpty())
                    continue;

                if (grid[iColumn][iFullCell1].getValue() == grid[iColumn][iFullCell2].getValue()) {
                    grid[iColumn][iFullCell1].doubleValue();
                    grid[iColumn][iFullCell2].resetValue();
                    move = true;
                }
            }
        }
    }

    for (int iColumn = 0; iColumn < 4; iColumn++) {
        for (int iEmptyCell = 3; iEmptyCell >= 0; iEmptyCell--) {
            if (grid[iColumn][iEmptyCell].getValue() != 0)
                continue;

            for (int iFullCell = iEmptyCell - 1; iFullCell >= 0; iFullCell--) {
                if (grid[iColumn][iFullCell].isEmpty())
                    continue;

                Cell& oEmptyCell = grid[iColumn][iEmptyCell];
                Cell& oFullCell = grid[iColumn][iFullCell];

                oEmptyCell.setValue(oFullCell);
                oFullCell.resetValue();
                move = true;
                break;
            }
        }
    }

    return move;
}

bool Grid::moveLeft() {

    bool move = false;

    for (int iColumn = 0; iColumn < 4; iColumn++) {
        for (int iFullCell1 = 0; iFullCell1 <= 3; iFullCell1++) {
            if (grid[iColumn][iFullCell1].isEmpty()) {
                continue;
            }

            for (int iFullCell2 = iFullCell1 + 1; iFullCell2 <= 3; iFullCell2++) {
                if (grid[iColumn][iFullCell2].isEmpty())
                    continue;

                if (grid[iColumn][iFullCell1].getValue() == grid[iColumn][iFullCell2].getValue()) {
                    grid[iColumn][iFullCell1].doubleValue();
                    grid[iColumn][iFullCell2].resetValue(); 
                    move = true;
                }
            }
        }
    }

    for (int iColumn = 0; iColumn < 4; iColumn++) {
        for (int iEmptyCell = 0; iEmptyCell <= 3; iEmptyCell++) {
            if (grid[iColumn][iEmptyCell].getValue() != 0)
                continue;

            for (int iFullCell = iEmptyCell + 1; iFullCell <= 3; iFullCell++) {
                if (grid[iColumn][iFullCell].isEmpty()) 
                    continue;

                Cell& oEmptyCell = grid[iColumn][iEmptyCell];
                Cell& oFullCell = grid[iColumn][iFullCell];

                oEmptyCell.setValue(oFullCell);
                oFullCell.resetValue();
                move = true;
                break;
            }
        }
    }

    return move;
}

bool Grid::moveDown() {

    bool move = false;

    for (int jRow = 0; jRow < 4; jRow++) {
        for (int jFullCell1 = 3; jFullCell1 >= 0; jFullCell1--) {
            if (grid[jFullCell1][jRow].isEmpty()) {
                continue;
            }

            for (int jFullCell2 = jFullCell1 - 1; jFullCell2 >= 0; jFullCell2--) {
                if (grid[jFullCell2][jRow].isEmpty())
                    continue;

                if (grid[jFullCell1][jRow].getValue() == grid[jFullCell2][jRow].getValue()) {
                    grid[jFullCell1][jRow].doubleValue();
                    grid[jFullCell2][jRow].resetValue();
                    move = true;
                }
            }
        }
    }

    for (int jRow = 0; jRow < 4; jRow++) {
        for (int jEmptyCell = 3; jEmptyCell >= 0; jEmptyCell--) {
            if (grid[jEmptyCell][jRow].getValue() != 0)
                continue;

            for (int jFullCell = jEmptyCell - 1; jFullCell >= 0; jFullCell--) {
                if (grid[jFullCell][jRow].isEmpty())
                    continue;

                Cell& oEmptyCell = grid[jEmptyCell][jRow];
                Cell& oFullCell = grid[jFullCell][jRow];

                oEmptyCell.setValue(oFullCell);
                oFullCell.resetValue();
                move = true;
                break;
            }
        }
    }

    return move;
}

bool Grid::moveUp() {

    bool move = false;

    for (int jRow = 0; jRow < 4; jRow++) {
        for (int jFullCell1 = 0; jFullCell1 <= 3; jFullCell1++) {
            if (grid[jFullCell1][jRow].isEmpty()) {
                continue;
            }

            for (int jFullCell2 = jFullCell1 + 1; jFullCell2 <= 3; jFullCell2++) {
                if (grid[jFullCell2][jRow].isEmpty())
                    continue;

                if (grid[jFullCell1][jRow].getValue() == grid[jFullCell2][jRow].getValue()) {
                    grid[jFullCell1][jRow].doubleValue();
                    grid[jFullCell2][jRow].resetValue();
                    move = true;
                }
            }
        }
    }

    for (int jRow = 0; jRow < 4; jRow++) {
        for (int jEmptyCell = 0; jEmptyCell <= 3; jEmptyCell++) {

            if (grid[jEmptyCell][jRow].getValue() != 0)
                continue;

            for (int jFullCell = jEmptyCell + 1; jFullCell <= 3; jFullCell++) {
                
                if (grid[jFullCell][jRow].isEmpty())
                    continue;

                Cell& oEmptyCell = grid[jEmptyCell][jRow];
                Cell& oFullCell = grid[jFullCell][jRow];

                oEmptyCell.setValue(oFullCell);
                oFullCell.resetValue();

                move = true;
                break;
            }
        }
    }

    return move;
}

void Grid::spawnCell() {

    int emptyCellNumber = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].isEmpty()) {
                emptyCellNumber++;
            }
        }
    }

    if (emptyCellNumber == 0)
        return;
    int randomNumber = rand() % emptyCellNumber;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].isEmpty()) {
                if (randomNumber == 0) {
                    grid[i][j].setValue(((rand() % 2) + 1) * 2);
                }
                randomNumber--;
            }
        }
    }

}

bool Grid::isDefeat() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].getValue() == 0) {
                return false;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        int temp = grid[i][0].getValue();
        for (int j = 1; j < 4; j++) {
            if (grid[i][j].getValue() == temp) {
                return false;
            }
            temp = grid[i][j].getValue();
        }
    }

    for (int i = 0; i < 4; i++) {
        int temp = grid[0][i].getValue();
        for (int j = 1; j < 4; j++) {
            if (grid[j][i].getValue() == temp) {
                return false;
            }
            temp = grid[j][i].getValue();
        }
    }

    return true;
}

/*
bool Grid::compare(int config[4][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].getValue() != config[i][j]) {
                return false;
            }
        }
    }

    return true;
}
*/