/*
#include "test.hpp"

Test::Test()
{
}

Test::~Test()
{
}

void Test::test() {

    int setup[4][4] =
    {
        {4,4,4,0},
        {8,0,4,0},
        {16,8,0,0},
        {32,16,2,0},
    };

    int result[4][4] =
    {
        {0,64,32,2},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
    };

    Grid gridTest(setup);

    gridTest.moveLeft();
    gridTest.moveDown();
    gridTest.moveDown();
    gridTest.moveDown();
    gridTest.moveRight();
    gridTest.moveUp();

    bool success = gridTest.compare(result);

    if (success == true)
    {
        std::cout << "Okay" << std::endl;
    }
    else
        std::cout << "Nope" << std::endl;

}
*/