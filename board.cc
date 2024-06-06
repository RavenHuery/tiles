// Written by Raven Huery

#include <iomanip>
#include <vector>
#include "board.h"
#include "tileType.h"

using namespace std;

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

board::board() {
    //Create all the tiles
    numberTile one(1);
    numberTile two(2);
    numberTile three(3);
    numberTile four(4);
    numberTile five(5);
    numberTile six(6);
    numberTile seven(7);
    numberTile eight(8);
    emptyTile empty();
    //add them to vector in no particular order
    order.push_back(one);
    order.push_back(two);
    order.push_back(three);
    order.push_back(four);
    order.push_back(five);
    order.push_back(six);
    order.push_back(seven);
    order.push_back(eight);
    order.push_back(empty);
    //set tile order using function
    setOrder();
}

void board::printBoard() {
    cout << "The board goes here" << endl;
    //Need a function to order all tiles in order of ref #
    vector<tileType> order (getOrder());

    cout << " " << order[0].getValue() << " | " << order[1].getValue() << " | " << order[2].getValue() << '\n';
         << "-----------\n";
         << " " << order[3].getValue() << " | " << order[4].getValue() << " | " << order[5].getValue() << '\n';
         << "-----------\n";
         << " " << order[6].getValue() << " | " << order[7].getValue() << " | " << order[8].getValue() << '\n' << endl;
}

void board::setOrder() {
    int j;
    cout << "The board is set in the following configuration... \n\n";
         << " <TILE 1> | <TILE 2> | <TILE 3> \n";
         << "--------------------------------\n";
         << " <TILE 4> | <TILE 5> | <TILE 6> \n";
         << "--------------------------------\n";
         << " <TILE 7> | <TILE 8> | <TILE 9> \n" << endl;
    

    //I am unsure if this could even work but its worth a shot. Enums are very epic imo.
    for (int i = 1; i < 10; i++) {
        enum tileNum seq;
        seq = i;
        cout << "Please enter the numerical value for TILE " << i;
             << ". If the empty tile is there, input a \"-1\"... " << endl;
        cin >> j;
        seq.setVal(j);
    }

    // cout << "Please enter the numerical value for TILE 1. If the empty tile is there, input a \"-1\"... " << endl;
    // cin >> uno;
    // one.setVal(uno);

    // cout <<"Please enter the numerical value for TILE 2. If the empty tile is there, input a \"-1\"... " << endl;
    // cin >> dos;
    // one.setVal(dos);
}

vector<tileType> board::getOrder() {
    vector<tileType> order;
    enum tileNum seq;
    for (int i = 1; i < 10; i++) { //i is the ref we want to add to vector
        for (int j = 1; j < 10; j++) { //j is the tile we are looking at via the enum
            seq = j;
            if (seq.getRef() == i)
                order.push_back(seq);
        }
    }

    return order;
}