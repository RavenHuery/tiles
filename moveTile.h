//Written by Raven Huery

#ifndef MOVE_TILE_H
#define MOVE_TILE_H

#include <iomanip>
#include <vector>

#include "tileType.h"

using namespace std;

class moveTile {
    public:

    //class constructor
    moveTile();

    //class destructor
    ~moveTile();

    //shift a tile from one position to another
    void shiftTile(tileType*, tileType*);

    protected:
    //takes two tiles and returns true if the move is legal and false otherwise
    bool isLegal(tileType*, tileType*);

    //checks if there is a free space next to a specified tile
    bool spaceFree(tileType*, tileType*);

    //Checks if the two tiles are adjacent
    bool isAdjacent(tileType*, tileType*);
};

#endif //MOVE_TILE_H