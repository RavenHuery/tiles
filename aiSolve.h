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

    vector<tileType*> state; //board state
    int f; //heuristic value
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

    //Function to get the heuristic value
    //takes in the current and goal ref and returns the heuristic
    int getHeuristic(int, int);

    private:
    vector<tileType*> goalState;
<<<<<<< HEAD

    //absolute value calculator
    
    int abs(int);
=======
    node startState;
    vector<node> openList;
    vector<node> closedList;
>>>>>>> 4860e2ee2d1f9c27d8f2acefe3ddbad99dbb9844
};

#endif //AI_H