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


aiSolve::aiSolve() {
    //Create a new vector that is the goal state of the search
    cout << "We will now build aiSolve object!!!" << endl;
    numberTile* one = new numberTile(1, 1);
    numberTile* two = new numberTile(2, 2);
    numberTile* three = new numberTile(3, 3);
    numberTile* four = new numberTile(4, 4);
    numberTile* five = new numberTile(5, 5);
    numberTile* six = new numberTile(6, 6);
    numberTile* seven = new numberTile(7, 7);
    numberTile* eight = new numberTile(8, 8);
    emptyTile* empty = new emptyTile(9);

    cout << "tiles have been created! Now adding to goalState!" << endl;

    goalState.order.push_back(one);
    goalState.order.push_back(two);
    goalState.order.push_back(three);
    goalState.order.push_back(four);
    goalState.order.push_back(five);
    goalState.order.push_back(six);
    goalState.order.push_back(seven);
    goalState.order.push_back(eight);
    goalState.order.push_back(empty);

    cout << "YIPPIE! Construction of aiSolve is now complete!" << endl;
}

aiSolve::~aiSolve() {
    for (auto t : goalState.order) {
        delete t;
    }
    goalState.order.clear();
}

bool aiSolve::aStar(board startBoard, int& turns) {
    //Initialize Open List
    // -Done during class constructor
    cout << "OK! Now it is time to set the startState!" << endl;
    startState.setBoard(startBoard.order);
    cout << "startState.setBoard(startBoard.order); is ok!" << endl;
    startState.setG(0);
    cout << "startState.setG(0); is ok!" << endl;
    startState.setF(startState.state);
    cout << "startState.setF(startState.state); is ok!" << endl;

    //Initialize closed list
    // -Done during class constructor

    //Put starting node in open
    openList.push_back(startState);
    cout << "startState added to openList" << endl;

    //While open list is NOT empty
    cout << "while open list is not empty! <FOR LOOP>" << endl;
    while (!openList.empty()) {
        //Find node with lowest heuristic value
        int leastF = INT_MAX; 
        cout << "leastF = INT_MAX" << endl;
        int leastFpos;
        for (unsigned int i = 0; i < openList.size(); i++) {
            if (openList[i].getF() < leastF) {
                leastF = openList[i].getF();
                leastFpos = i;
            }
        }
        cout << "WE FOUND IT! We found the one with the lowest F value!" << endl;
        //Call the current node q
        node q = openList[leastFpos];
        cout << "assigned the lowest to 'q'" << endl;
        //Print board of q
        q.state.printBoard(); // <------------ HERE IS WHERE IT SEGFAULTS!!!

        //pop q from open list
        openList.erase(openList.begin()+leastFpos);
        cout << "now we have removed q from openList" << endl;


        //Generate successors to q 
        int n = genSucc(q, goalState, q.getG());

        //for each successor
        for (int i = 0; i < n; i++) {
            bool addToList = true;

            //a) if the successor is the goal then we are done
            if (children[i].getBoard() == goalState) {
                return true; //This means we found the solution
            }
            
            //b) compute g and h for successor (for f value)
            //This is already done in the constructor for each child

            //c) if node has the same positioning as one in openList with higher f value, skip this one!
            //Check ALL nodes in openList, if there is a duplicate node in openList with a LOWER f value... skip!
            for (unsigned int j = 0; j < openList.size(); j++) {
                if (children[i].getBoard() == openList[j].getBoard() && children[i].getF() > openList[j].getF()) {
                    //skip this one. DON'T ADD IT TO OPEN LIST
                    addToList = false;
                }
            }

            //d) If successor has same pos as node in CLOSED list with lower f value, skip this one!
            //Check ALL nodes in closedList, if there is a duplicate with a LOWER h value then skip!
            for (unsigned int k = 0; k < closedList.size(); k++) {
                if (children[i].getBoard() == closedList[k].getBoard() && children[i].getF() > closedList[k].getF()) {
                    addToList = false;
                }
            }

            //Otherwise, add to openList
            if (addToList==true) {
                openList.push_back(children[i]);
            }
        }
        children.clear();

        //add q to closed list
        closedList.push_back(q);  

        turns++;      
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
