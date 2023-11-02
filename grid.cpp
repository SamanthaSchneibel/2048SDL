#include "grid.hpp"

Grid::Grid()
{
}

/*
Grid::Grid(Cell config[4][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            grid[i][j].value = config[i][j].value;
        }
    }
}
*/

Grid::~Grid()
{
}

void Grid::display() {

    system("cls");

    std::cout << "-------------------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "|";
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].value > 512)
                std::cout << grid[i][j].value << " |";
            else if (grid[i][j].value > 64)
                std::cout << grid[i][j].value << "  |";
            else if (grid[i][j].value > 8)
                std::cout << grid[i][j].value << "   |";
            else if (grid[i][j].value == 0)
                std::cout << "     |";
            else if (grid[i][j].value < 16)
                std::cout << grid[i][j].value << "    |";
        }
        std::cout << std::endl << "-------------------------" << std::endl;
    }

}

bool Grid::moveRight() {

    bool move = false;

    for (int iColumn = 0; iColumn < 4; iColumn++) {
        for (int iFullCell1 = 3; iFullCell1 >= 0; iFullCell1--) {
            if (grid[iColumn][iFullCell1].value == 0) {
                continue;
            }

            for (int iFullCell2 = iFullCell1 - 1; iFullCell2 >= 0; iFullCell2--) {
                if (grid[iColumn][iFullCell2].value == 0)
                    continue;

                if (grid[iColumn][iFullCell1].value == grid[iColumn][iFullCell2].value) {
                    grid[iColumn][iFullCell1].value *= 2;
                    grid[iColumn][iFullCell2].value = 0;
                    move = true;
                }
            }
        }
    }

    for (int iColumn = 0; iColumn < 4; iColumn++) {
        for (int iEmptyCell = 3; iEmptyCell >= 0; iEmptyCell--) {
            if (grid[iColumn][iEmptyCell].value != 0)
                continue;

            for (int iFullCell = iEmptyCell - 1; iFullCell >= 0; iFullCell--) {
                if (grid[iColumn][iFullCell].value == 0)
                    continue;

                grid[iColumn][iEmptyCell].value = grid[iColumn][iFullCell].value;
                grid[iColumn][iFullCell].value = 0;
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
            if (grid[iColumn][iFullCell1].value == 0) {
                continue;
            }

            for (int iFullCell2 = iFullCell1 + 1; iFullCell2 <= 3; iFullCell2++) {
                if (grid[iColumn][iFullCell2].value == 0)
                    continue;

                if (grid[iColumn][iFullCell1].value == grid[iColumn][iFullCell2].value) {
                    grid[iColumn][iFullCell1].value *= 2;
                    grid[iColumn][iFullCell2].value = 0;
                    move = true;
                }
            }
        }
    }

    for (int iColumn = 0; iColumn < 4; iColumn++) {
        for (int iEmptyCell = 0; iEmptyCell <= 3; iEmptyCell++) {
            if (grid[iColumn][iEmptyCell].value != 0)
                continue;

            for (int iFullCell = iEmptyCell + 1; iFullCell <= 3; iFullCell++) {
                if (grid[iColumn][iFullCell].value == 0)
                    continue;

                grid[iColumn][iEmptyCell].value = grid[iColumn][iFullCell].value;
                grid[iColumn][iFullCell].value = 0;
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
            if (grid[jFullCell1][jRow].value == 0) {
                continue;
            }

            for (int jFullCell2 = jFullCell1 - 1; jFullCell2 >= 0; jFullCell2--) {
                if (grid[jFullCell2][jRow].value == 0)
                    continue;

                if (grid[jFullCell1][jRow].value == grid[jFullCell2][jRow].value) {
                    grid[jFullCell1][jRow].value *= 2;
                    grid[jFullCell2][jRow].value = 0;
                    move = true;
                }
            }
        }
    }

    for (int jRow = 0; jRow < 4; jRow++) {
        for (int jEmptyCell = 3; jEmptyCell >= 0; jEmptyCell--) {
            if (grid[jEmptyCell][jRow].value != 0)
                continue;

            for (int jFullCell = jEmptyCell - 1; jFullCell >= 0; jFullCell--) {
                if (grid[jFullCell][jRow].value == 0)
                    continue;

                grid[jEmptyCell][jRow].value = grid[jFullCell][jRow].value;
                grid[jFullCell][jRow].value = 0;
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
            if (grid[jFullCell1][jRow].value == 0) {
                continue;
            }

            for (int jFullCell2 = jFullCell1 + 1; jFullCell2 <= 3; jFullCell2++) {
                if (grid[jFullCell2][jRow].value == 0)
                    continue;

                if (grid[jFullCell1][jRow].value == grid[jFullCell2][jRow].value) {
                    grid[jFullCell1][jRow].value *= 2;
                    grid[jFullCell2][jRow].value = 0;
                    move = true;
                }
            }
        }
    }

    for (int jRow = 0; jRow < 4; jRow++) {
        for (int jEmptyCell = 0; jEmptyCell <= 3; jEmptyCell++) {
            if (grid[jEmptyCell][jRow].value != 0)
                continue;

            for (int jFullCell = jEmptyCell + 1; jFullCell <= 3; jFullCell++) {
                if (grid[jFullCell][jRow].value == 0)
                    continue;

                grid[jEmptyCell][jRow].value = grid[jFullCell][jRow].value;
                grid[jFullCell][jRow].value = 0;
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
            if (grid[i][j].value == 0) {
                emptyCellNumber++;
            }
        }
    }

    if (emptyCellNumber == 0)
        return;
    int randomNumber = rand() % emptyCellNumber;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].value == 0) {
                if (randomNumber == 0) {
                    grid[i][j].value = ((rand() % 2) + 1) * 2;
                }
                randomNumber--;
            }
        }
    }

}

bool Grid::isDefeat() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].value == 0) {
                return false;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        int temp = grid[i][0].value;
        for (int j = 1; j < 4; j++) {
            if (grid[i][j].value == temp) {
                return false;
            }
            temp = grid[i][j].value;
        }
    }

    for (int i = 0; i < 4; i++) {
        int temp = grid[0][i].value;
        for (int j = 1; j < 4; j++) {
            if (grid[j][i].value == temp) {
                return false;
            }
            temp = grid[j][i].value;
        }
    }

    return true;
}

/*
bool Grid::compare(int config[4][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].value != config[i][j]) {
                return false;
            }
        }
    }

    return true;
}
*/