// Written by Raven Huery

#include <iomanip>

using namespace std;

class board {
    public: 

    // class constructor
    board();

    // class deconstructor
    ~board();

    // display board via cout
    void printBoard();

    protected:
    // sets the order of the tiles on board. 
    void setOrder();
};