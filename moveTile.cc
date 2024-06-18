//Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>
#include "moveTile.h"

using namespace std;

moveTile::moveTile() {

}

moveTile::~moveTile() {
    
}

void moveTile::shiftTile(tileType* a, tileType* b) {
    if (isLegal(a, b) == true) {
        int newB = a->getRef();
        int newA = b->getRef();
        a->setRef(newA);
        b->setRef(newB);
        cout << "Shift has been completed!" << endl;
    }
    else {
        cout << "You can't do that! That move is ILLEGAL! Try again... " << endl;
    }
}

bool moveTile::isLegal(tileType* a, tileType* b) {
    bool freeSpace = spaceFree(a, b); //Is one empty and another numerical?
    bool isAdj = isAdjacent(a, b); //Are the two tiles right next to each other?
    if (freeSpace == true && isAdj == true) 
        return true;
    return false;
}

bool moveTile::spaceFree(tileType* a, tileType* b) {
    bool aFree = a->isEmpty();
    bool bFree = b->isEmpty();
    if ((aFree == false && bFree == true) || (aFree == true && bFree == false))
        return true;
    return false;
}

bool moveTile::isAdjacent(tileType* a, tileType* b) {
    int aRef = a->getRef();
    int bRef = b->getRef();
    int diff = aRef - bRef;
    if ((diff == 1) || (diff == -1) || (diff == 3) || (diff == -3))
        return true;
    return false;
}