//Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>
#include <string>

#include "game.h"
#include "board.h"
#include "moveTile.h"
#include "aiSolve.h"

using namespace std;

game::game() {
    isVictorious = isVictory();
    giveUp = false;
    gameBoard.setOrder();
}

game::~game() {

}

bool game::isVictory() {
    for (int i = 0; i < 9; i++) {
        if (gameBoard.order[i]->getRef() != gameBoard.order[i]->getValue()) { 
            if ((gameBoard.order[i]->isEmpty() != true) || (gameBoard.order[i]->getRef() != 9)) { 
                return false;
            }
        }
    }
    return true;
}

void game::takeAction() {
    string select;
    std::cout << "What move would you like to make?\n"
         << "Select 'm' to move a tile\n"
         << "Select 'q' to quit the program\n"
         << "Select 'a' to get AI to solve the puzzle\n\n"
         << "Input: ";
    cin >> select;
    if (select == "m" || select == "M") {
        tileMove();
    }
    if (select == "q" || select == "Q") {
        giveUp = true;
    }
    if (select == "a" || select == "A") {
        //cout << "AI algorithm sounds\n\n" << endl;
        int t = 0;
        bool huh;
        aiSolve robot;
        cout << "now we will call aStar function!" << endl;
        huh = robot.aStar(getGameBoard(), t); // <---THIS IS WHERE WE CALL A*
        cout << "The AI can solve this board in " << t << " moves!" << endl;
        cout << "algorithm returns " << huh << endl;
        giveUp = true;
    }
}

void game::tileMove() {
    moveTile move; 
    vector<int> legalNum = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int posA, posB;
    do {
        cout << "Please enter the position of the tile you would like to move...\n";
        cin >> posA;
    } while (!gameBoard.inArray(legalNum, posA));
    do {
        cout << "Please enter the position you would like to move the tile to...\n";
        cin >> posB;
    } while (!gameBoard.inArray(legalNum, posB));

    //find where in the vector the tile is...
    int tileA = gameBoard.findTilePos(posA);
    int tileB = gameBoard.findTilePos(posB);

    //make the move
    move.shiftTile(gameBoard.order[tileA], gameBoard.order[tileB]);
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

        while (isVictorious != true) {
            gameBoard.printBoard();
            takeAction();
            if (giveUp == true) {
                break;
            }
            isVictorious = isVictory();
        };
        if (isVictorious == true){
            gameBoard.printBoard();
            cout << "\n\n\nCongratulations, you did it! \n\n\n" << endl;
        }
    }
}

board game::getGameBoard() {
    return gameBoard;
}