//Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>
#include <climits>

#include "aiSolve.h"

using namespace std;

node::node(vector<tileType*> board, int g) {
    for (int i = 0; i < 9; i++) {
        state.push_back(board[i]);
    }
    f = h(state) + g;
}

node::~node() {
    auto (t : state) {
        delete t;
    }
    state.clear();
}

int node::h(vector<tileType*>& curState, vector<tileType*>& goalState) {
    int h = 0;
    for (int i = 0; i < 9; i++) {
        int n = curState[i]->getRef(); //current ref
        int m = goalState[i]->getRef(); //goal ref
        h = h + abs(n-m) + abs(n/3 - m/3);
    }
    return h;
}

int node::abs(int x) {
    if (x < 0)
        return x/-1;
    return x;
}

int node::getF() {
    return f;
}

aiSolve::aiSolve(vector<tileType*>& start) {
    //Create a new vector that is teh goal state of the search
    numberTile* one = new numberTile(1, 1);
    numberTile* two = new numberTile(2, 2);
    numberTile* three = new numberTile(3, 3);
    numberTile* four = new numberTile(4, 4);
    numberTile* five = new numberTile(5, 5);
    numberTile* six = new numberTile(6, 6);
    numberTile* seven = new numberTile(7, 7);
    numberTile* eight = new numberTile(8, 8);
    emptyTile* empty = new emptyTile(9);

    goalState.push_back(one);
    goalState.push_back(two);
    goalState.push_back(three);
    goalState.push_back(four);
    goalState.push_back(five);
    goalState.push_back(six);
    goalState.push_back(seven);
    goalState.push_back(eight);
    goalState.push_back(empty);

    node* startState = new node(start, 0);
}

aiSolve::~aiSolve() {
    for (auto t : goalState) {
        delete t;
    }
    goalState.clear();
}

bool aiSolve::aStar() {
    //Initialize Open List
    // -Done during class constructor

    //Initialize closed list
    // -Done during class constructor

    //Put starting node in open
    openList.push_back(startState);

    //While open list is NOT empty
    while (!openList.empty()) {
        //Find node with lowest heuristic value
        int leastF = INT_MAX; 
        int leastFpos;
        for (int i = 0; i < openList.size(); i++) {
            if (openList[i].getF() < leastF) {
                leastF = openList[i].getF();
                leastFpos = i;
            }
        }
        //Call the current node q
        node q = openList[leastFpos];

        //pop q from open list
        openList.erase(openList.begin+leastFpos);

        //Generate successors to q ~~NEED A FUNCTION THAT DOES THAT~~

    }
}

//Generate children with a given parent UwU
void aiSolve::genSucc(node parent, int parentG) {
    //Find emptyTile in parent.state
    int emptyRef;
    bool up = false, down = false, left = false, right = false;
    moveTile moveOp;
    for (int i = 0; i < 9; i++) {
        if (parent.state[i]->getValue() == -1) {
            emptyRef = i;
            break;
        }
    }
    //Generate new refs, discard those that are out of range

    //generate ref - 3
    if (emptyRef != 1 || emptyRef != 2 || emptyRef != 3) { //Check if its in range
        node upNode(parent, parentG);
        moveOp.shiftTile(upNode.state[emptyRef], upNode.state[emptyRef - 3]);
        up = true;
    }

    //generate ref - 1
    if (emptyRef != 1 || emptyRef != 4 || emptyRef != 7) {
        node leftNode(parent, parentG);
        moveOp.shiftTile(leftNode.state[emptyRef], leftNode.state[emptyRef - 1]);
        left = true;
    }

    //generate ref + 1
    if (emptyRef != 3 || emptyRef != 6 || emptyRef != 9) {
        node rightNode(parent, parentG);
        moveOp.shiftTile(rightNode.state[emptyRef], rightNode.state[emptyRef +1]);
        right = true;
    }

    //generate ref + 3
    if (emptyRef != 7 || emptyTile != 8 || emptyTile != 9) {
        node downNode(parent, parentG);
        moveOp.shiftTile(downNode.state[emptyRef], downNode.state[emptyRef + 3]);
        down = true;
    }

    //create new nodes based on the new refs, add to openList
    if (up == true)
        openList.push_back(upNode);
    if (down == true)
        openList.push_back(downNode);
    if (left == true)
        openList.push_back(leftNode);
    if (right == true)
        openList.push_back(rightNode);
}
