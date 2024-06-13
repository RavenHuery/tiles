// Written by Raven Huery

#ifndef TILE_TYPE_H
#define TILE_TYPE_H

#include <iomanip>

using namespace std;

class tileType {
    public:
    //Class constructor
    tileType();

    //class destructor
    ~tileType();

    //pure virtual isEmpty function
    virtual bool isEmpty();

    //pure virtual isNumber function
    virtual bool isNumber();

    //get the numerical value of tile
    int getValue();

    //get the reference number of the tile
    int getRef();

    //Sets the numerical value of the tile
    void setVal(int v);

    //Sets the reference point on board for tile
    void setRef(int r);

    protected:
    int value; //tile number. If <0 then its empty
    int ref; //reference to place on board
};

class emptyTile : public tileType {
    public: 
    //class constructor
    emptyTile(int r);

    //class destructor
    ~emptyTile();

    //isEmpty function returns true because it is empty
    bool isEmpty();

    //isNumber function returns false because it is not a number
    bool isNumber();
};

class numberTile : public tileType {
    public: 
    //class constructor
    numberTile(int r, int v);

    //class destructor
    ~numberTile();

    //isEmpty function returns false because it is not empty
    bool isEmpty();

    //isNumber function returns true because it is a number
    bool isNumber();
};

#endif //TILE_TYPE_H