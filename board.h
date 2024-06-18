// Written by Raven Huery

#ifndef BOARD_H
#define BOARD_H

#include <iomanip>
#include <vector>

#include "tileType.h"

using namespace std;

class board {
    public: 
    vector<tileType*> order;

    // class constructor
    board();

    // class deconstructor
    ~board();

    // display board via cout
    void printBoard();

    //Find a tile's position in vector given a Ref
    int findTilePos(int);

    protected:

    // sets the order of the tiles on board. 
    void setOrder();

    //Gets the order of tiles based on ref number
    //A vector of pointers!
    vector<tileType*> getOrder();
};

#endif //BOARD_H