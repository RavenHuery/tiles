//Written by Raven Huery

#include <iomanip>
#include <vector>
#include "moveTile.h"
#include "board.h"
#include "tileType.h"
#include "game.h"

using namespace std;

game::game() {
    isVictorious = isVictory();

}

game::~game() {

}

bool game::isVictory() {
    for (int i = 1; i < 10; i++) {
        if (gameBoard.order[i].getRef() != gameBoard.order[i].getValue()) { //if tile ref != tile value
            //check if tile is empty and if ref is 9. Thats where the empty tile should be
            if ((gameBoard.order[i].isEmpty() == true) && (gameBoard.order[i].getRef() == 9)) { 
                continue;
            }
            else {
                //empty tile is in wrong place or numerical tile value does not match ref. victory is not yet reached
                return false; 
            }
        }
    }
    return true;
}

void game::takeAction() {
    char select;
    do {
        cout << "What move would you like to make?\n";
             << "Select 'm' to move a tile\n";
             << "Select 'q' to quit the program\n\n";
             << "Input: ";
        cin >> select;
        if (select == 'm' || select == 'M') {
            //do stuff here
        } else if (select == 'q' || select == 'Q') {
            break;
        }
    } while (isVictorious == false);
}

void game::moveTile() {
    moveTile move(); 
    //Need a function to search for tiles in the vector
    int refA, refB, posA, posB;
    cout << "\nWhat tile would you like to move?\n";
         << "Input tile position as an integer (i.e. 1, 2, 3, 4, 5, 6, 7, 8, 9): ";
    cin >> refA;
    cout << "\nWhere would you like that tile to go?\n";
         << "Input tile position as an integer (i.e. 1, 2, 3, 4, 5, 6, 7, 8, 9): ";
    cin >> refB;
    //find tile positions in vector
    posA = gameBoard.findTilePos(refA);
    posB = gameBoard.findTilePos(refB);
    
    move.shiftTyle(gameBoard.order[posA], gameBoard.order[posB]);
}