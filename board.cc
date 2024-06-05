// Written by Raven Huery

#include <iomanip>
#include "board.h"
#include "tileType.h"

using namespace std;

board::board() {
    numberTile one(8, 1);
    numberTile two(1, 2);
    numberTile three(3, 3);
    numberTile four(2, 4);
    numberTile five(7, 5);
    numberTile six(6, 6);
    numberTile seven(9, 7);
    numberTile eight(4, 8);
    emptyTile empty(5);
}

void board::printBoard() {
    cout << "The board goes here" << endl;
}

void board::setOrder() {
    enum tileNum {
        1 = one,
        2 = two,
        3 = three,
        4 = four,
        5 = five,
        6 = six,
        7 = seven,
        8 = eight,
        9 = nine,
    };

    int j;
    cout << "The board is set in the following configuration... \n\n";
         << " <TILE 1> | <TILE 2> | <TILE 3> \n";
         << "---------------------------------\n";
         << " <TILE 4> | <TILE 5> | <TILE 6> \n";
         << "---------------------------------\n";
         << " <TILE 7> | <TILE 8> | <TILE 9> \n" << endl;
    
    for (int i = 1; i < 10; i++) {
        enum tileNum seq;
        seq = i;
        cout << "Please enter the numerical value for TILE " << i;
             << ". If the empty tile is there, input a \"-1\"... " << endl;
        cin >> j;
        one.setVal(j);
    }

    cout << "Please enter the numerical value for TILE 1. If the empty tile is there, input a \"-1\"... " << endl;
    cin >> uno;
    one.setVal(uno);

    cout <<"Please enter the numerical value for TILE 2. If the empty tile is there, input a \"-1\"... " << endl;
    cin >> dos;
    one.setVal(dos);

    cout << "Please enter the numerical value for TILE 1. If the empty tile is there, input a \"-1\"... " << endl;
    cin >> uno;
    one.setVal(uno);

    cout << "Please enter the numerical value for TILE 1. If the empty tile is there, input a \"-1\"... " << endl;
    cin >> uno;
    one.setVal(uno);

    cout << "Please enter the numerical value for TILE 1. If the empty tile is there, input a \"-1\"... " << endl;
    cin >> uno;
    one.setVal(uno);

    cout << "Please enter the numerical value for TILE 1. If the empty tile is there, input a \"-1\"... " << endl;
    cin >> uno;
    one.setVal(uno);
    
}