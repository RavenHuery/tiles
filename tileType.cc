// Written by Raven Huery

#include <iomanip>

#include "tileType.h"

using namespace std;

bool emptyTile::isEmpty() {
    return true;
}

bool emptyTile::isNumber() {
    return false;
}

bool numberTile::isEmpty() {
    return false;
}

bool numberTile::isNumber() {
    return true;
}