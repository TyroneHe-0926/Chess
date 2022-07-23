#include "human.h"
#include <iostream>
using namespace std;

Human::Human(bool side) : side{side} {}
    
bool Human::getSide() { return side; }

move Human::getNextMove(){
    pair<pair<char, int>, pair<char, int>> result;
    pair<char, int> inputs;
    pair<char, int> targets;
    char inCol,outCol;
    int inRow, outRow;
    cin>>inCol>>inRow>>outCol>>outRow;
    inputs = make_pair(inCol, inRow);
    targets = make_pair(outCol, outRow);
    result = make_pair(inputs, targets);
    return result;
}
