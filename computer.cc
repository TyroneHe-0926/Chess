#include "computer.h"
#include <algorithm>
using namespace std;

Computer::Computer(bool side, int diff) : side{side}, difficulty{diff}{}

int Computer::getDiff(){ return difficulty; }

bool Computer::getSide(){ return side; }

PlayerType Computer::getPlayerType(){ return computer; }

//helper function that returns a random move from move list
ChessMove randomMove(vector<PossibleMoves> pm){
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

//level 1 just picks a random move
ChessMove getLevel1Move(vector<PossibleMoves> pm){
    return randomMove(pm);
}

//helper function for getting a list of moves that possibly captures an opponent piece
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

//level 2 focus on capture and checks
ChessMove getLevel2Move(vector<PossibleMoves> pm, Board* b, bool side){
    ChessMove result;
    vector<PossibleMoves> lvl2MoveList = getLevel2MoveList(pm, b, side);

    //if we do have a list of moves that potentially leads to a capture
    if(!lvl2MoveList.empty()){ 
        for(auto myMove : lvl2MoveList){
            for(auto d : myMove.destination){
                //if this in fact is a check, we want to go there first
                if(b->getType(d).first == PieceType::King){
                    result.first = myMove.start;
                    result.second = d;
                }
                //if not checks are avalible, we just capture a random piece.
                else{
                    result = randomMove(lvl2MoveList); 
                }
            }
        }
    }
    //if we dont have any captures, just perform a random move
    else { result = randomMove(pm); }
    return result;
}

//get a list of moves that avoids getting captured
vector<PossibleMoves> getLevel3MoveList(vector<PossibleMoves> pm, Board* b, bool side){
    vector<PossibleMoves> noCapList;
    vector<PossibleMoves> lvl3MoveList;
    vector<Position> badPositions;
    vector<PossibleMoves> oppoMoveList = b->getAllAvailableMoves(!side);

    //get the list of positions that will cause the opoonent able to capture our piece
    for(auto oMove : oppoMoveList){
        for(auto d : oMove.destination){
            badPositions.emplace_back(d);
        }
    }
    
    //fiter out the bad positions and construct the level 3 list
    for(auto myMove : pm){
        PossibleMoves theMove;
        theMove.start = myMove.start;
        theMove.destination = {};
        for(auto d : myMove.destination){
            if(!(find(badPositions.begin(), badPositions.end(), d) != badPositions.end())) {
                theMove.destination.emplace_back(d);
            }
        }
        if(!theMove.destination.empty()){ noCapList.emplace_back(theMove); }
    }

    //now we want to apply the logic from level 2 to focus on cpaturing and checking
    //while avoiding getting captured
    lvl3MoveList = getLevel2MoveList(noCapList, b, side);

    return lvl3MoveList;
}

//lvl 3 computer avoids getting captured and focus on capturing and checking
ChessMove getLevel3Move(vector<PossibleMoves> pm, Board* b, bool side){
    ChessMove result;
    vector<PossibleMoves> lvl3MoveList = getLevel3MoveList(pm, b, side);
    
    //if no move is avalible to both avoid capturing and capture at the same time
    //we check to see if we can apply level 2
    if(!lvl3MoveList.empty()){ result = randomMove(lvl3MoveList); }
    else{ result = getLevel2Move(pm, b, side); }
    return result;
}

ChessMove getLevel4Move(vector<PossibleMoves> pm, Board* b, bool side){}

ChessMove Computer::getNextMove(Board* b){
    vector<PossibleMoves> movelist = b->getAllAvailableMoves(side);
    vector<PossibleMoves> pmList;
    
    //first we shouldn't be able to move pieces that will cause the king to be checked
    for(auto pm : movelist){
        Position start_pos = pm.start;
        vector<Position> dest = pm.destination;
        PossibleMoves curMove;
        curMove.start = start_pos;
        curMove.destination = {};
        for(auto d : dest){
            ChessMove target = make_pair(start_pos, d);
            ChessMove back = make_pair(d, start_pos);
            b->testMove(target);
            if(b->inCheck(side)){
                b->badMove(back);
                continue;
            }
            curMove.destination.emplace_back(d);
            b->badMove(back);
        }
        if(!curMove.destination.empty()){ pmList.emplace_back(curMove); }
    }

    //if no moves are avalible, its stalemate
    if(pmList.empty()){
        ChessMove staleGame = make_pair(make_pair(A, -2), make_pair(A, -2));
        return staleGame;
    }
    
    ChessMove result;
    //level one just makes a random move
    if(difficulty == 1){
        result = getLevel1Move(pmList);
    }

    //level two perfers capturing moves and check over other moves
    if(difficulty == 2){
        result = getLevel2Move(pmList, b, side);
    }

    //level three avoids captures, perfers capturing moves and checks 
    if(difficulty == 3){
        result = getLevel3Move(pmList, b, side);
    }

    if(difficulty == 4){
        result = getLevel4Move(pmList, b, side);
    }

    //use our algorithm according to diff level to calculate the result and return
    b->nextMove(result);

    //check if this move kills the opponent
    if(checkMate(b, side)){
        ChessMove endGame = make_pair(make_pair(A, -1), make_pair(A, -1));
        return endGame;
    }
    return result;
}
