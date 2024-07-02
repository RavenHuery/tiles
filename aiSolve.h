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

class aiSolve {
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
    bool aStar(vector<tileType*>&);

    //Function to get the heuristic value
    //takes in the current and goal ref and returns the heuristic
    int getHeuristic(int, int);

    private:
    vector<tileType*> goalState;

    //absolute value calculator
    
    int abs(int);
};

#endif //AI_H