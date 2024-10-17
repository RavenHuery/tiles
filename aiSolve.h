//Written by Raven Huery

#ifndef AI_H
#define AI_H

#include <iomanip>
#include <vector>
#include "tileType.h"
#include "board.h"
#include "moveTile.h"

using namespace std;

class node{
    public:

    node();
    // //constructor that copies a board and generates
    // //a heuristic value using the g value
    // node(vector<tileType*>&, board&, int);

    //constructor that copies a board and generates
    //a heuristic value using the g value
    node(node, board&, int);

    //destructor
    ~node();

    //get h value for heuristic
    int h(board&, board&);

    //absolute value calculator
    int abs(int);

    //Get number of successions
    int getG();

    //set G value
    void setG(int);

    //Get node heuristic
    int getF();

    //Set f value using a board
    void setF(board&);

    // Setup a board for a new Node
    board setupNewBoard(node);

    board getBoard();

    //Function to set node state space
    void setBoard(node);

    board state; //board state
    int f; //heuristic value
    int g;
};

class aiSolve{
    public:

    //class constructor
    aiSolve();

    //destructor
    ~aiSolve();

    //A* search algorithm to solve the puzzle
    //........................................
    //Heuristic is sum of manhattan distance each tile is away
    //from its correct position (h value)
    //........................................
    //Count sum of tile distance away from starting position (g value)
    bool aStar(board, int&);

    //Generate successor states from a given node
    //Addes new states to openList
    int genSucc(node, board&, int);

    private:
    board goalState;
    node startState;
    vector<node> openList;
    vector<node> closedList;
    vector<node> children;
};

#endif //AI_H