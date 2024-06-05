// Written by Raven Huery

#include <iomanip>
#include "board.h"
#include "tileType.h"

using namespace std;

board::board() {
    numberTile one(1);
    numberTile two(2);
    numberTile three(3);
    numberTile four(4);
    numberTile five(5);
    numberTile six(6);
    numberTile seven(7);
    numberTile eight(8);
    emptyTile empty();
}

void board::printBoard() {
    cout << "The board goes here" << endl;