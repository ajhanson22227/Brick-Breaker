#include "Game.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    Game game({800, 600}, 125, 20, 20, 75, 20);
    game.run();
    return 0;
}