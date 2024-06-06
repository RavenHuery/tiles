//Written by Raven Huery

#include <iomanip>
#include <vector>
#include "moveTile.h"
#include "board.h"
#include "tileType.h"

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
    void moveTile();

    protected:
    board gameBoard();
    bool isVictorious;
}