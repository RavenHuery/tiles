// Written by Raven Huery

#include <iomanip>

#include "tileType.h"

using namespace std;

int tileType::getValue() {
    return value;
}

void tileType::setVal(int v = 0) {
    value = v;
}

int tileType::getRef() {
    return ref;
}

void tileType::setRef(int r = 0) {
    ref = r;
}

emptyTile::emptyTile(int r = 0) {
    setVal(-1);
    setRef(r);
}

bool emptyTile::isEmpty() {
    return true;
}

bool emptyTile::isNumber() {
    return false;
}

numberTile::numberTile(int r = 0, int v = 0) {
    setRef(r);
    setVal(v);
}

bool numberTile::isEmpty() {
    return false;
}

bool numberTile::isNumber() {
    return true;
}
