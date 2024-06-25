//Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>

#include "game.h"
#include "board.h"
#include "moveTile.h"

using namespace std;

game::game() {
    isVictorious = isVictory();
    giveUp = false;

}

game::~game() {

}

bool game::isVictory() {
    for (int i = 0; i < 9; i++) {
        if (gameBoard.order[i]->getRef() != gameBoard.order[i]->getValue()) { //if tile ref != tile value
            //check if tile is empty and if ref is 9. Thats where the empty tile should be
            if ((gameBoard.order[i]->isEmpty() != true) || (gameBoard.order[i]->getRef() != 9)) { 
                return false;
            }
        }
    }
    return true;
}

void game::takeAction() {
    char select;
    moveTile pMove;
    //do {
    std::cout << "What move would you like to make?\n"
         << "Select 'm' to move a tile\n"
         << "Select 'q' to quit the program\n\n"
         << "Input: ";
    cin >> select;
    if (select == 'm' || select == 'M') {
        //IMPLEMENT SHIT HERE!!!
        int posA, posB;
        cout << "Please enter the position of the tile you would like to move...\n";
        cin >> posA;
        cout << "Please enter the position you would like to move the tile to...\n";
        cin >> posB;

        //find where in the vector the tile is...
        int tileA = gameBoard.findTilePos(posA);
        int tileB = gameBoard.findTilePos(posB);

        //make the move

        pMove.shiftTile(gameBoard.order[tileA], gameBoard.order[tileB]);
        cout << "Move has been made!" << endl;
    }
    if (select == 'q' || select == 'Q') {
        giveUp = true;
    }
}

void game::tileMove() {
    moveTile move; 
    //Need a function to search for tiles in the vector
    int refA, refB, posA, posB;
    std::cout << "\nWhat tile would you like to move?\n"
         << "Input tile position as an integer (i.e. 1, 2, 3, 4, 5, 6, 7, 8, 9): ";
    std::cin >> refA;
    std::cout << "\nWhere would you like that tile to go?\n"
         << "Input tile position as an integer (i.e. 1, 2, 3, 4, 5, 6, 7, 8, 9): ";
    std::cin >> refB;
    //find tile positions in vector
    posA = gameBoard.findTilePos(refA);
    posB = gameBoard.findTilePos(refB);
    
    move.shiftTile(gameBoard.order[posA], gameBoard.order[posB]);
}

void game::playGame() {
    char ans;
    do {
        cout << "Would you like to play a game? (y/n) ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y') 
            break;
        if (ans == 'n' || ans == 'N')
            break;
    } while (ans != 'y' || ans != 'Y' || ans != 'n' || ans != 'N');
    if (ans == 'y' || ans == 'Y') {
        isVictorious = isVictory();
        cout << "game playing sounds" << std::endl;

        while (isVictorious != true) {
            gameBoard.printBoard();
            takeAction();
            if (giveUp == true) {
                break;
            }
            isVictorious = isVictory();
        };
        if (isVictorious == true) 
            cout << "Congratulations, you did it! \n\n\n" << endl;
    }
}