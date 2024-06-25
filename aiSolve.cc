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
}

aiSolve::~aiSolve() {

}

bool aiSolve::aStar() {

}