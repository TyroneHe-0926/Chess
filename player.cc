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
            b->nextMove(target);
            if(!b->inCheck(opp)){
                b->nextMove(back);
                return false;
            }
            b->nextMove(back);
        }
    }
    return true;
}