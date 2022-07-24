#include "computer.h"
using namespace std;

Computer::Computer(bool side, int diff) : side{side}, difficulty{diff}{}

int Computer::getDiff(){ return difficulty; }

bool Computer::getSide(){ return side; }

ChessMove Computer::getNextMove(Board* b){
    vector<PossibleMoves> pm = b->getAllAvailableMoves(side, b);
    int l = pm.size();
    ChessMove result;
    if(difficulty == 1){
        int f =  rand()%l;
        result.first = pm.at(f).start;
        int s = rand()%pm.at(f).destination.size();
        result.second = pm.at(f).destination.at(s);
    }
    if(difficulty == 2){
        int f =  rand()%l;
        result.first = pm.at(f).start;
        int s = rand()%pm.at(f).destination.size();
        result.second = pm.at(f).destination.at(s);
    }
    //use our algorithm according to diff level to calculate the result and return
    b->nextMove(result);
    return result;
}
