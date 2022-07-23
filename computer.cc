#include "computer.h"
using namespace std;

Computer::Computer(bool side, int diff) : side{side}, difficulty{diff}{}

int Computer::getDiff(){ return difficulty; }

bool Computer::getSide(){ return side; }

ChessMove Computer::getNextMove(Board&){
    ChessMove result;
    //use our algorithm according to diff level to calculate the result and return
    return result;
}
