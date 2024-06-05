//Written by Raven Huery

#include <iomanip>
#include <vector>
#include "board.h"
#include "tileType.h"
#include "moveTile.h"

using namespace std;

moveTile::shiftTile(tileType a, tileType b) {

}

moveTile::isLegal(tileType a, tileType b) {
    int aRef = a.getRef(); //primary
    int bRef = b.getRef(); //secondary
    bool spaceAvailable; //Is one empty and another numerical?
    bool simpleShift; //Are the two tiles right next to each other?

    
}