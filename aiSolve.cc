//Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>

#include "aiSolve.h"

using namespace std;

aiSolve::aiSolve() {
    //Create a new vector that is teh goal state of the search
    numberTile* one = new numberTile(1, 1);
    numberTile* two = new numberTile(2, 2);
    numberTile* three = new numberTile(3, 3);
    numberTile* four = new numberTile(4, 4);
    numberTile* five = new numberTile(5, 5);
    numberTile* six = new numberTile(6, 6);
    numberTile* seven = new numberTile(7, 7);
    numberTile* eight = new numberTile(8, 8);
    emptyTile* empty = new emptyTile(9);

    goalState.push_back(one);
    goalState.push_back(two);
    goalState.push_back(three);
    goalState.push_back(four);
    goalState.push_back(five);
    goalState.push_back(six);
    goalState.push_back(seven);
    goalState.push_back(eight);
    goalState.push_back(empty);
}

aiSolve::~aiSolve() {
    for (auto t : goalState) {
        delete t;
    }
    goalState.clear();
}

bool aiSolve::aStar() {

}

int aiSolve::abs(int x) {
    if (x < 0)
        return x/-1;
    return x;
}

int aiSolve::h(vector<tileType*>& curState) {
    int h = 0;
    for (int i = 0; i < 9; i++) {
        int n = curState[i]->getRef(); //current ref
        int m = goalState[i]->getRef(); //goal ref
        h = h + abs(n-m) + abs(n/3 - m/3);
    }
    return h;
}