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

    vector<tileType*> pOrder;
    getOrder(order, pOrder);

    cout << " " << pOrder[0]->getValue() << " | " << pOrder[1]->getValue() << " | " << pOrder[2]->getValue() << '\n'
         << "-----------\n"
         << " " << pOrder[3]->getValue() << " | " << pOrder[4]->getValue() << " | " << pOrder[5]->getValue() << '\n'
         << "-----------\n"
         << " " << pOrder[6]->getValue() << " | " << pOrder[7]->getValue() << " | " << pOrder[8]->getValue() << '\n' << endl;
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
    vector<int> spotAvailable = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "The board is set in the following configuration... \n\n"
         << " <TILE 1> | <TILE 2> | <TILE 3> \n"
         << "--------------------------------\n"
         << " <TILE 4> | <TILE 5> | <TILE 6> \n"
         << "--------------------------------\n"
         << " <TILE 7> | <TILE 8> | <TILE 9> \n" << endl;
    
    do {
        cout << "\n\nPlease enter the position (1-9) of the tile with a '1' on it ..." << endl;
        cin >> j;
    } while (!inArray(spotAvailable, j));
    order[0]->setRef(j);
    adjAvailable(spotAvailable, j);

    do {
        cout << "\n\nPlease enter the position (1-9) of the tile with a '2' on it ..." << endl;
        cin >> j;
    } while (!inArray(spotAvailable, j));
    order[1]->setRef(j);
    adjAvailable(spotAvailable, j);

    do {
        cout << "\n\nPlease enter the position (1-9) of the tile with a '3' on it ..." << endl;
        cin >> j;
    } while (!inArray(spotAvailable, j));
    order[2]->setRef(j);
    adjAvailable(spotAvailable, j);

    do {
        cout << "\n\nPlease enter the position (1-9) of the tile with a '4' on it ..." << endl;
        cin >> j;
    } while (!inArray(spotAvailable, j));
    order[3]->setRef(j);
    adjAvailable (spotAvailable, j);

    do {
        cout << "\n\nPlease enter the position (1-9) of the tile with a '5' on it ..." << endl;
        cin >> j;
    } while (!inArray(spotAvailable, j));
    order[4]->setRef(j);
    adjAvailable (spotAvailable, j);

    do {
        cout << "\n\nPlease enter the position (1-9) of the tile with a '6' on it ..." << endl;
        cin >> j;
    } while (!inArray(spotAvailable, j));
    order[5]->setRef(j);
    adjAvailable (spotAvailable, j);

    do {
        cout << "\n\nPlease enter the position (1-9) of the tile with a '7' on it ..." << endl;
        cin >> j;
    } while (!inArray(spotAvailable, j));
    order[6]->setRef(j);
    adjAvailable (spotAvailable, j);

    do {
        cout << "\n\nPlease enter the position (1-9) of the tile with a '8' on it ..." << endl;
        cin >> j;
    } while (!inArray(spotAvailable, j));
    order[7]->setRef(j);
    adjAvailable(spotAvailable, j);

    do {
        cout << "\n\nPlease enter the position (1-9) of the empty tile ..." << endl;
        cin >> j;
    } while (!inArray(spotAvailable, j));
    order[8]->setRef(j);
    adjAvailable(spotAvailable, j);  
}

void board::getOrder(vector<tileType*> mainOrder, vector<tileType*>& newOrder) {
    for (int i = 1; i < 10; i++) { //i is the position of the new vector
        for (int j = 0; j < 9; j++) { //j is the position of the main vector
            if (mainOrder[j]->getRef() == i)
                newOrder.push_back(mainOrder[j]);
        }
    }
}

void board::adjAvailable(vector<int>& ava, int j) {
    for (unsigned int i = 0; i < ava.size()-1; i++) {
        if (ava[i] == j) {
            ava.erase(ava.begin()+i);
        }
    }
}

bool board::inArray(vector<int>& ava, int j) {
    for (int i = 0; i < 9; i++) {
        if (ava[i] == j)
            return true;
    }
    return false;
}