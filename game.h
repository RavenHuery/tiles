//Written by Raven Huery

#ifndef GAME_H
#define GAME_H

#include <iomanip>
#include <vector>
#include "board.h"

using namespace std;

class game {
    public:

    //class constructor
    game();

    //class deconstructor
    ~game();

    //checks to see if victory has been achieved.
    bool isVictory();

    //Ask for user input to do stuff
    void takeAction();

    //Calls functions from moveTile class and gets relevant info
    void tileMove();

    //Calls to start the game
    void playGame();

    //returns the gameboard
    board getGameBoard();

    protected:
    board gameBoard;
    bool isVictorious;
    bool giveUp;
}; 

#endif //GAME_H