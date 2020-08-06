#include "Game.h"

int main(){
    Game game({800, 600}, 125, 20, 20, 75, 20);
    game.run();
    return 0;
}