// Written by Raven Huery

#include <iomanip>

#include "tileType.h"

using namespace std;

emptyTile::emptyTile(int r) {
    value = -1;
    ref = r;
}

bool emptyTile::isEmpty() {
    return true;
}

bool emptyTile::isNumber() {
    return false;
}

numberTile::numberTile(int r, int v = 1) {
    ref = r;
    value = v;
}

bool numberTile::isEmpty() {
    return false;
}

bool numberTile::isNumber() {
    return true;
}

int numberTile::getValue() {
    return value;
}