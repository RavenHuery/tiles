// Written by Raven Huery

#include <iomanip>

#include "tileType.h"

using namespace std;

tileType::tileType() {
    //Stuff happens here
    value = 0;
    ref = 0;
}
tileType::~tileType() {
    //stuff happens here
}

bool tileType::isEmpty() {
    return true;
}

bool tileType::isNumber() {
    return true;
}

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

emptyTile::emptyTile() {
    setVal(-1);
    setRef(0);
}

emptyTile::~emptyTile() {
    //stuff happens here
}

bool emptyTile::isEmpty() {
    return true;
}

bool emptyTile::isNumber() {
    return false;
}

numberTile::numberTile(int v = 0, int r = 0) {
    setRef(r);
    setVal(v);
}

numberTile::numberTile(int v = 0) {
    setRef(0);
    setVal(v);
}

numberTile::~numberTile() {
    //stuff gets destroyed herecd
}

bool numberTile::isEmpty() {
    return false;
}

bool numberTile::isNumber() {
    return true;
}
