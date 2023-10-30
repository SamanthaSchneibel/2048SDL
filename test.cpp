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
        {0,0,0,0},
        {32,0,32,0},
        {0,0,0,0},
        {0,0,0,0},
    };

    int result[4][4] =
    {
        {0,0,0,0},
        {0,0,0,64},
        {0,0,0,0},
        {0,0,0,0},
    };

    Grid gridTest(setup);

    gridTest.moveRight();

    bool success = gridTest.compare(result);

    if (success == true)
    {
        std::cout << "Okay" << std::endl;
    }
    else
        std::cout << "Nope" << std::endl;

}