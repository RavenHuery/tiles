// Written by Raven Huery

#include <iomanip>

using namespace std;

class tileType {
    protected:

    //Class constructor
    tileType();

    //class destructor
    ~tileType();

    //pure virtual isEmpty function
    virtual bool isEmpty()=0;

    //pure virtual isNumber function
    virtual bool isNumber()=0;
}

class emptyTile : public tileType {
    protected: 

    //class constructor
    emptyTile();

    //class destructor
    ~emptyTile();

    //isEmpty function returns true because it is empty
    bool isEmpty();

    //isNumber function returns false because it is not a number
    bool isNumber();
}

class numberTile : public tileType {
    protected: 

    //class constructor
    numberTile();

    //class destructor
    ~numberTile();

    //isEmpty function returns false because it is not empty
    bool isEmpty();

    //isNumber function returns true because it is a number
    bool isNumber();
}