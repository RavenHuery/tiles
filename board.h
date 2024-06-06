// Written by Raven Huery

#include <iomanip>
#include <vector>

using namespace std;

class board {
    public: 
    vector<tileType> order;

    // class constructor
    board();

    // class deconstructor
    ~board();

    // display board via cout
    void printBoard();

    //Find a tile's position in vector given a Ref
    int findTilePos(int);

    protected:

    // sets the order of the tiles on board. 
    void setOrder();

    //Gets the order of tiles based on ref number
    vector<tileType> getOrder();
};