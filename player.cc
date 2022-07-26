#include "player.h"
#include <vector>
using namespace std;



bool Player::checkMate(Board* b, bool side){
    //check if its checkmate after a move was made by side
    //should do this check by first getting all avalible moves for the opponent
    //and check if any of those moves could stop him getting check mated.

    bool opp = !side;
    vector<PossibleMoves> pmList = b->getAllAvailableMoves(opp);

    for(auto pm : pmList){
        Position start_pos = pm.start;
        vector<Position> dest = pm.destination;
        for(auto d : dest){
            ChessMove target = make_pair(start_pos, d);
            ChessMove back = make_pair(d, start_pos);
            b->testMove(target, false);
            if(!b->inCheck(opp)){
                b->badMove(back, false);
                return false;
            }
            b->badMove(back, false);
        }
    }
    return true;
}

bool Player::checkStale(Board* b, bool side){
    vector<PossibleMoves> myMoves = b->getAllAvailableMoves(side);
    for(auto myMove : myMoves){
        for(auto d : myMove.destination){
            //if we can get to a king, that means we are not staled
            if(b->getType(d).first == PieceType::King){
                return false;
            }
        }
    }
    return true;
}