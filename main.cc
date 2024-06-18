//Written by Raven Huery

#include <iomanip>
#include <vector>
#include "game.h"
#include "moveTile.h"
#include "board.h"
#include "tileType.h"

using namespace std;

int main() {
    game theGame;
    theGame.playGame();
    return 0;
}

//June 18, 2024
//User is prompted to input board config and then program seg faults
//board::setOrder() runs to create game board. 