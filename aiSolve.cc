//Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>
#include <climits>

#include "aiSolve.h"

using namespace std;

//Does not compile. My guess is that we have two constructors with the same amount of params
//Try making a default that accepts zero params

node::node(vector<tileType*>& board, vector<tileType*>& goal, int gVal) {
    for (int i = 0; i < 9; i++) {
        state.push_back(board[i]);
    }
    g = gVal;
    setF(goal);
}

node::node(node copyNode, vector<tileType*>& goal, int gVal) {
    for (int i = 0; i < 9; i++) {
        state.push_back(copyNode.state[i]);
    }
    g = gVal;
    setF(goal);
}

node::~node() {
    for (auto t : state) {
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

int node::getG() {
    return g;
}

int node::getF() {
    return f;
}

void node::setF(vector<tileType*>& goal) {
    f = h(state, goal) + g;
}

//When the vector is creating StartState node it does not have the required parameters!
//This constructor needs to be changed
aiSolve::aiSolve(vector<tileType*>& startBoard) {
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

    node startState(startBoard, goalState, 0);
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
        for (unsigned int i = 0; i < openList.size(); i++) {
            if (openList[i].getF() < leastF) {
                leastF = openList[i].getF();
                leastFpos = i;
            }
        }
        //Call the current node q
        node q = openList[leastFpos];

        //pop q from open list
        openList.erase(openList.begin()+leastFpos);

        //Generate successors to q ~~NEED A FUNCTION THAT DOES THAT~~
        genSucc(q, goalState, q.getG());

        //for each successor
        //a) if the successor is the goal then we are done
        //b) compute g and h for successor (for f value)
        //c) if node has the same positioning as one in openList with higher f value, skip this one!
        //d) If successor has same pos as node in CLOSED list with lower f value, skip this one!
        //</for>

        //add q to closed list
        
    }
    return false;
}

//Generate children with a given parent UwU
void aiSolve::genSucc(node parent, vector<tileType*>& goal, int parentG) {
    //Find emptyTile in parent.state
    int emptyRef;
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
        node upNode(parent, goal, parentG + 1);
        moveOp.shiftTile(upNode.state[emptyRef], upNode.state[emptyRef - 3]);
        upNode.setF(goal);
        openList.push_back(upNode);
    }

    //generate ref - 1
    if (emptyRef != 1 || emptyRef != 4 || emptyRef != 7) {
        node leftNode(parent, goal, parentG + 1);
        moveOp.shiftTile(leftNode.state[emptyRef], leftNode.state[emptyRef - 1]);
        leftNode.setF(goal);
        openList.push_back(leftNode);
    }

    //generate ref + 1
    if (emptyRef != 3 || emptyRef != 6 || emptyRef != 9) {
        node rightNode(parent, goal, parentG + 1);
        moveOp.shiftTile(rightNode.state[emptyRef], rightNode.state[emptyRef +1]);
        rightNode.setF(goal);
        openList.push_back(rightNode);
    }

    //generate ref + 3
    if (emptyRef != 7 || emptyRef != 8 || emptyRef != 9) {
        node downNode(parent, goal, parentG + 1);
        moveOp.shiftTile(downNode.state[emptyRef], downNode.state[emptyRef + 3]);
        downNode.setF(goal);
        openList.push_back(downNode);
    }

    //create new nodes based on the new refs, add to openList
    
}
