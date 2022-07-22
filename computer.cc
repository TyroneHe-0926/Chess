#include "computer.h"
using namespace std;

Computer::Computer(int side, int diff) : side{side}, difficulty{diff}{}

int Computer::getSide(){ return side; }

pair<pair<char, int>, pair<char, int>> Computer::getNextMove(){
    pair<pair<char, int>, pair<char, int>> result;
    pair<char, int> inputs;
    pair<char, int> targets;
    //use our algorithm according to diff level to calculate the result and return
    return result;
}
