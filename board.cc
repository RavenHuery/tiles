// Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>
#include "board.h"

using namespace std;


board::board() {
    //Create all the tiles
    numberTile* one = new numberTile(1);
    numberTile* two = new numberTile(2);
    numberTile* three = new numberTile(3);
    numberTile* four = new numberTile(4);
    numberTile* five = new numberTile(5);
    numberTile* six = new numberTile(6);
    numberTile* seven = new numberTile(7);
    numberTile* eight = new numberTile(8);
    emptyTile* empty = new emptyTile();

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

board::~board() {
    for (auto t : order) {
        delete t;
    }
    order.clear();
}

void board::printBoard() {
    cout << "\n------------------------------\n" << endl;
    //Need a function to order all tiles in order of ref #
    //vector<tileType*> order (getOrder());

    cout << " " << order[0]->getValue() << " | " << order[1]->getValue() << " | " << order[2]->getValue() << '\n'
         << "-----------\n"
         << " " << order[3]->getValue() << " | " << order[4]->getValue() << " | " << order[5]->getValue() << '\n'
         << "-----------\n"
         << " " << order[6]->getValue() << " | " << order[7]->getValue() << " | " << order[8]->getValue() << '\n' << endl;
}

int board::findTilePos(int r) {
    for (int i = 0; i < 9; i++) {
        if (r == order[i]->getRef()) {
            return i;
        }
    }
    return -1;
}

void board::setOrder() {
    int j;
    cout << "The board is set in the following configuration... \n\n"
         << " <TILE 1> | <TILE 2> | <TILE 3> \n"
         << "--------------------------------\n"
         << " <TILE 4> | <TILE 5> | <TILE 6> \n"
         << "--------------------------------\n"
         << " <TILE 7> | <TILE 8> | <TILE 9> \n" << endl;
    

    //Takes the tile position and asks for num value. However, it assumes tile 9 is empty!
    //May need to change so it sets ref based on num value
    cout << "\n\nPlease enter the position (1-9) of the tile with a '1' on it ..." << endl;
    cin >> j;
    order[0]->setRef(j);

    cout << "Tile with a 1 on it is set to " << order[0]->getRef() << endl;

    cout << "\n\nPlease enter the position (1-9) of the tile with a '2' on it ..." << endl;
    cin >> j;
    order[1]->setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '3' on it ..." << endl;
    cin >> j;
    order[2]->setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '4' on it ..." << endl;
    cin >> j;
    order[3]->setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '5' on it ..." << endl;
    cin >> j;
    order[4]->setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '6' on it ..." << endl;
    cin >> j;
    order[5]->setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '7' on it ..." << endl;
    cin >> j;
    order[6]->setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the tile with a '8' on it ..." << endl;
    cin >> j;
    order[7]->setRef(j);

    cout << "\n\nPlease enter the position (1-9) of the empty tile ..." << endl;
    cin >> j;
    order[8]->setRef(j);

    //If I don't use keypad it segfaults. WHY???
    cout << "The empty tile is set to " << order[8]->getRef() << endl;    
}

// //Take in oldOrder as order vector class member
// //output newOrder in the form of a vector of tiles
// //Re-orders tiles in order of reference number


// ~~~~~~~~DEBUG CODE BEFORE IMPLEMENTING~~~~~~~~~~~~
vector<tileType*> board::getOrder() {
//     vector<tileType*> newOrder;
//     // enum tileNum seq;
//     for (int i = 1; i < 10; i++) { //i is the ref we want to add to vector
//         for (int j = 1; j < 10; j++) { //j is the tile we are looking at via the enum
//             seq = j;
//             if (seq.getRef() == i)
//                 order.push_back(seq);
//         }
//     }

//     return newOrder;
    vector <tileType*> order; 
    return order;
}