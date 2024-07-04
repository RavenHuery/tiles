//Written by Raven Huery

#include <iomanip>
#include <vector>
#include <iostream>
#include <climits>

#include "aiSolve.h"

using namespace std;

//Does not compile. My guess is that we have two constructors with the same amount of params
//Try making a default that accepts zero params

//Node needs a "set board" function

node::node() {
    setG(0);
    board newBoard(9);
    numberTile* one = new numberTile(1, 1);
    numberTile* two = new numberTile(2, 2);
    numberTile* three = new numberTile(3, 3);
    numberTile* four = new numberTile(4, 4);
    numberTile* five = new numberTile(5, 5);
    numberTile* six = new numberTile(6, 6);
    numberTile* seven = new numberTile(7, 7);
    numberTile* eight = new numberTile(8, 8);
    emptyTile* empty = new emptyTile(9);

    newBoard.order.push_back(one);
    newBoard.order.push_back(two);
    newBoard.order.push_back(three);
    newBoard.order.push_back(four);
    newBoard.order.push_back(five);
    newBoard.order.push_back(six);
    newBoard.order.push_back(seven);
    newBoard.order.push_back(eight);
    newBoard.order.push_back(empty);
    setBoard(newBoard.order);
    setF(newBoard);
}

node::node(vector<tileType*>& newBoard, board& goal, int gVal) {
    setBoard(newBoard);
    setG(gVal);
    setF(goal);
}

node::node(node copyNode, board& goal, int gVal) {
    setBoard(copyNode.getBoard().order);
    setG(gVal);
    setF(goal);
}

node::~node() {
    for (auto t : state.order) {
        delete t;
    }
    state.order.clear();
}

int node::h(board& curState, board& goalState) {
    int h = 0;
    for (int i = 0; i < 9; i++) {
        int n = curState.order[i]->getRef(); //current ref
        int m = goalState.order[i]->getRef(); //goal ref
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

void node::setG(int newG) {
    g = newG;
}

int node::getF() {
    return f;
}

void node::setF(board& goal) {
    f = h(state, goal) + g;
}

board node::getBoard() {
    return state;
}

void node::setBoard(vector<tileType*> newBoard) {
    for (int i = 0; i < 9; i++) {
        state.order.push_back(newBoard[i]);
    }
}

//When the vector is creating StartState node it does not have the required parameters!
//This constructor needs to be changed
aiSolve::aiSolve() {
    //Create a new vector that is the goal state of the search
    numberTile* one = new numberTile(1, 1);
    numberTile* two = new numberTile(2, 2);
    numberTile* three = new numberTile(3, 3);
    numberTile* four = new numberTile(4, 4);
    numberTile* five = new numberTile(5, 5);
    numberTile* six = new numberTile(6, 6);
    numberTile* seven = new numberTile(7, 7);
    numberTile* eight = new numberTile(8, 8);
    emptyTile* empty = new emptyTile(9);

    goalState.order.push_back(one);
    goalState.order.push_back(two);
    goalState.order.push_back(three);
    goalState.order.push_back(four);
    goalState.order.push_back(five);
    goalState.order.push_back(six);
    goalState.order.push_back(seven);
    goalState.order.push_back(eight);
    goalState.order.push_back(empty);
}

aiSolve::~aiSolve() {
    for (auto t : goalState.order) {
        delete t;
    }
    goalState.order.clear();
}

bool aiSolve::aStar(vector<tileType*> startBoard) {
    //Initialize Open List
    // -Done during class constructor
    startState.setBoard(startBoard);
    startState.setG(0);
    startState.setF(startState.state);

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
        //Print board of q

        //pop q from open list
        openList.erase(openList.begin()+leastFpos);

        //Generate successors to q 
        int n = genSucc(q, goalState, q.getG());

        //for each successor
        for (int i = 0; i < n; i++) {
            if (children[i].getBoard() == goalState) //need overloaded == operator
            //!!!!!BEGIN IMPLEMENTING STUFF HERE NEXT TIME!!!!!
        }
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
int aiSolve::genSucc(node parent, board& goal, int parentG) {
    //Find emptyTile in parent.state
    int n = 0;
    int emptyRef;
    moveTile moveOp;
    for (int i = 0; i < 9; i++) {
        if (parent.state.order[i]->getValue() == -1) {
            emptyRef = i;
            break;
        }
    }
    //Generate new refs, discard those that are out of range

    //generate ref - 3
    if (emptyRef != 1 || emptyRef != 2 || emptyRef != 3) { //Check if its in range
        node upNode(parent, goal, parentG + 1);
        moveOp.shiftTile(upNode.state.order[emptyRef], upNode.state.order[emptyRef - 3]);
        upNode.setF(goal);
        children.push_back(upNode);
        n++;
    }

    //generate ref - 1
    if (emptyRef != 1 || emptyRef != 4 || emptyRef != 7) {
        node leftNode(parent, goal, parentG + 1);
        moveOp.shiftTile(leftNode.state.order[emptyRef], leftNode.state.order[emptyRef - 1]);
        leftNode.setF(goal);
        children.push_back(leftNode);
        n++;
    }

    //generate ref + 1
    if (emptyRef != 3 || emptyRef != 6 || emptyRef != 9) {
        node rightNode(parent, goal, parentG + 1);
        moveOp.shiftTile(rightNode.state.order[emptyRef], rightNode.state.order[emptyRef +1]);
        rightNode.setF(goal);
        children.push_back(rightNode);
        n++;
    }

    //generate ref + 3
    if (emptyRef != 7 || emptyRef != 8 || emptyRef != 9) {
        node downNode(parent, goal, parentG + 1);
        moveOp.shiftTile(downNode.state.order[emptyRef], downNode.state.order[emptyRef + 3]);
        downNode.setF(goal);
        children.push_back(downNode);
        n++;
    }

    //create new nodes based on the new refs, add to openList
    return n;
}
