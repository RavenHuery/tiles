// Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>
#include "board.h"

using namespace std;

// enum tileNum { //this does not work lol
//     1 = one,
//     2 = two,
//     3 = three,
//     4 = four,
//     5 = five,
//     6 = six,
//     7 = seven,
//     8 = eight,
//     9 = nine,
// };

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

int board::findTilePos(int r) {
    for (int i = 1; i < 10; i++) {
        if (r == order[i].getRef()) (
            return i;
        )
    }
}

void board::setOrder() {
    int j;
    cout << "The board is set in the following configuration... \n\n";
         << " <TILE 1> | <TILE 2> | <TILE 3> \n";
         << "--------------------------------\n";
         << " <TILE 4> | <TILE 5> | <TILE 6> \n";
         << "--------------------------------\n";
         << " <TILE 7> | <TILE 8> | <TILE 9> \n" << endl;
    

    //Takes the tile position and asks for num value. However, it assumes tile 9 is empty!
    //May need to change so it sets ref based on num value
    cout << "\n\nPlease enter the position (1-9) of the tile with a '1' on it ..." << endl;
    cin >> j;
    one.setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '2' on it ..." << endl;
    cin >> j;
    two.setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '3' on it ..." << endl;
    cin >> j;
    three.setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '4' on it ..." << endl;
    cin >> j;
    four.setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '5' on it ..." << endl;
    cin >> j;
    five.setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '6' on it ..." << endl;
    cin >> j;
    six.setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '7' on it ..." << endl;
    cin >> j;
    seven.setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '8' on it ..." << endl;
    cin >> j;
    eight.setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the empty tile ..." << endl;
    cin >> j;
    empty.setRef(j);
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