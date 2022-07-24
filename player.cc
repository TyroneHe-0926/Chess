#include "player.h"
#include <vector>
using namespace std;

bool Player::inCheck(Board* b, bool side){
    //get all the possible moves the opponent can make
    vector<PossibleMoves> pm = b->getAllAvailableMoves(!side, b);

    //check if this side is in check
    for(auto m : pm){
        if(b->getType(m.start).second != side){
            for(auto d : m.destination){
                if(b->getType(d).first == PieceType::King){
                    return true;
                }
            }
        }
    }
    return false;
}

bool Player::checkMate(Board* b, bool side){
    //check if its checkmate after a move was made by side
    //should do this check by first getting all avalible moves for the opponent
    //and check if any of those moves could stop him getting check mated.

    bool opp = !side;
    vector<PossibleMoves> pmList = b->getAllAvailableMoves(opp, b);

    for(auto pm : pmList){
        Position start_pos = pm.start;
        vector<Position> dest = pm.destination;
        for(auto d : dest){
            ChessMove target = make_pair(start_pos, d);
            ChessMove back = make_pair(d, start_pos);
            b->nextMove(target);
            if(!inCheck(b, opp)){
                b->nextMove(back);
                return false;
            }
            b->nextMove(back);
        }
    }
    return true;
}