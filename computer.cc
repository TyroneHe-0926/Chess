#include "computer.h"
using namespace std;

Computer::Computer(bool side, int diff) : side{side}, difficulty{diff}{}

int Computer::getDiff(){ return difficulty; }

bool Computer::getSide(){ return side; }

PlayerType Computer::getPlayerType(){ return computer; }

ChessMove getLevel1Move(vector<PossibleMoves> pm){
    ChessMove result;
    int listLength = pm.size();
    int randomMove =  rand()%listLength;

    while((pm.at(randomMove).destination.empty())){
        randomMove =  rand()%listLength;
    }

    result.first = pm.at(randomMove).start;
    int s = rand()%pm.at(randomMove).destination.size();
    result.second = pm.at(randomMove).destination.at(s);
    return result;
}

vector<PossibleMoves> getLevel2MoveList(vector<PossibleMoves> pm, Board* b, bool side){
    vector<PossibleMoves> lvl2MoveList;
    for(auto move : pm){
        PossibleMoves theMove;
        theMove.start = move.start;
        theMove.destination = {};
        for(auto d : move.destination){
            if(b->getType(d).first != PieceType::Empty && b->getType(d).second != side){
                theMove.destination.emplace_back(d);
            }
        }
        if(!theMove.destination.empty()){ lvl2MoveList.emplace_back(theMove); }
    }
    return lvl2MoveList;
}

ChessMove getLevel2Move(vector<PossibleMoves> pm, Board* b, bool side){
    ChessMove result;
    vector<PossibleMoves> lvl2MoveList = getLevel2MoveList(pm, b, side);
    if(!lvl2MoveList.empty()){ result = getLevel1Move(lvl2MoveList); }
    else { result = getLevel1Move(pm); }
    return result;
}

ChessMove Computer::getNextMove(Board* b){
    vector<PossibleMoves> pm = b->getAllAvailableMoves(side);
    ChessMove result;
    //level one just makes a random move
    if(difficulty == 1){
        result = getLevel1Move(pm);
    }

    //level two perfers capturing moves and check over other moves
    if(difficulty == 2){
        result = getLevel2Move(pm, b, side);
    }

    //level three avoids captures, perfers capturing moves and checks 
    if(difficulty == 3){

    }

    //use our algorithm according to diff level to calculate the result and return
    b->nextMove(result);
    return result;
}
