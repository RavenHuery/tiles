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

    //constructor for aiSolve
    board(int);

    // class deconstructor
    ~board();

    //overloaded == operator for boards
    bool operator==(board);

    // display board via cout
    void printBoard();

    //Find a tile's position in vector given a Ref
    int findTilePos(int);

    //Checks if int is in array
    bool inArray(vector<int>&, int);

    //Edits array so that int gets removed
    void adjAvailable(vector<int> &, int);

    // sets the order of the tiles on board. 
    void setOrder();

    protected:

    //Gets the order of tiles based on ref number
    //A vector of pointers!
    void getOrder(vector<tileType*>, vector<tileType*>&);
};

#endif //BOARD_H