//Written by Raven Huery

#ifndef AI_H
#define AI_H

#include <iomanip>
#include <vector>
#include "tileType.h"
#include "board.h"
#include "moveTile.h"
#include "game.h"

using namespace std;

class node {
    public:
    //constructor that copies a board and generates
    //a heuristic value using the g value
    node(vector<tileType*>, int);

    //destructor
    ~node();

    //get h value for heuristic
    int h(vector<tileType*>);

    //absolute value calculator
    int abs(int);

    //Get number of successions
    int getG();

    //Get node heuristic
    int getF();

    //Set f value
    void setF();

    vector<tileType*> state; //board state
    int f; //heuristic value
    int g;
}

class aiSolve {
    public:

    //class constructor
    aiSolve(vector<tileType*> &);

    //destructor
    ~aiSolve();

    //A* search algorithm to solve the puzzle
    //........................................
    //Heuristic is sum of manhattan distance each tile is away
    //from its correct position (h value)
    //........................................
    //Count sum of tile distance away from starting position (g value)
    bool aStar(vector<tileType*>&);

    //Generate successor states from a given node
    //Addes new states to openList
    void genSucc(node);

    private:
    vector<tileType*> goalState;
    node startState;
    vector<node> openList;
    vector<node> closedList;
};

#endif //AI_H