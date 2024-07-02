//Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>

#include "aiSolve.h"

using namespace std;

<<<<<<< HEAD
aiSolve::aiSolve() {
    //Create a new vector that is the goal state of the search
=======
node::node(vector<tileType*> board, int g) {
    for (int i = 0; i < 9; i++) {
        state.push_back(board[i]);
    }
    f = h(state) + g;
}

node::~node() {
    auto (t : state) {
        delete t;
    }
    state.clear();
}

int node::h(vector<tileType*>& curState) {
    int h = 0;
    for (int i = 0; i < 9; i++) {
        int n = curState[i]->getRef(); //current ref
        int m = goalState[i]->getRef(); //goal ref
        h = h + abs(n-m) + abs(n/3 - m/3);
    }
    return h;
}

int node::abs(int x) {
    if (x < 0)
        return x/-1;
    return x;
}

aiSolve::aiSolve(vector<tileType*>& start) {
    //Create a new vector that is teh goal state of the search
>>>>>>> 4860e2ee2d1f9c27d8f2acefe3ddbad99dbb9844
    numberTile* one = new numberTile(1, 1);
    numberTile* two = new numberTile(2, 2);
    numberTile* three = new numberTile(3, 3);
    numberTile* four = new numberTile(4, 4);
    numberTile* five = new numberTile(5, 5);
    numberTile* six = new numberTile(6, 6);
    numberTile* seven = new numberTile(7, 7);
    numberTile* eight = new numberTile(8, 8);
<<<<<<< HEAD
    emptyTile* nine = new emptyTile(9);
=======
    emptyTile* empty = new emptyTile(9);
>>>>>>> 4860e2ee2d1f9c27d8f2acefe3ddbad99dbb9844

    goalState.push_back(one);
    goalState.push_back(two);
    goalState.push_back(three);
    goalState.push_back(four);
    goalState.push_back(five);
    goalState.push_back(six);
    goalState.push_back(seven);
    goalState.push_back(eight);
<<<<<<< HEAD
    goalState.push_back(nine);
=======
    goalState.push_back(empty);

    node* startState = new node(start, 0);
>>>>>>> 4860e2ee2d1f9c27d8f2acefe3ddbad99dbb9844
}

aiSolve::~aiSolve() {
    for (auto t : goalState) {
        delete t;
    }
    goalState.clear();
}

bool aiSolve::aStar() {

}
<<<<<<< HEAD

int aiSolve::getHeuristic(int n, int m) {

}

int aiSolve::abs(int x) {
    if (x < 0)
        return x/-1;
    else 
        return x;
}
=======
>>>>>>> 4860e2ee2d1f9c27d8f2acefe3ddbad99dbb9844
