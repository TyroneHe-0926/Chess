#include "computer.h"
#include <algorithm>
using namespace std;

Computer::Computer(bool side, int diff) : side{side}, difficulty{diff}{}

PlayerType Computer::getPlayerType(){ return computer; }

bool checkEmpty(vector<PossibleMoves> pm){
    for(auto m : pm){
        if(!m.destination.empty()){
            return false;
        }
    }
    return true;
}
//helper function that returns a random move from move list
ChessMove randomMove(vector<PossibleMoves> pm){
    //if no avalible moves are left, game is stale
    if(checkEmpty(pm)){
        ChessMove staleGame = make_pair(make_pair(A, -2), make_pair(A, -2));
        return staleGame;
    }
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

//helper function for getting a move that checks the opponents king
ChessMove getCheckMove(Board* b, bool side){
    ChessMove result = make_pair(make_pair(A, -1), make_pair(A, -1));
    vector<PossibleMoves> myMoves = b->getAllAvailableMoves(side);
    for(auto move : myMoves){
        Position start_pos = move.start;
        vector<Position> dest = move.destination;
        for(auto d : dest){
            ChessMove target = make_pair(start_pos, d);
            ChessMove back = make_pair(d, start_pos);
            b->testMove(target, false);
            if(b->inCheck(!side)){
                b->badMove(back, false);
                result.first = start_pos;
                result.second = d;
                return result;
            }
            b->badMove(back, false);
        }
    }
    return result;
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

//level 2 focus on checks first, and then captures
ChessMove getLevel2Move(vector<PossibleMoves> pm, Board* b, bool side){
    //first let's check if we do have a move that leads to a check
    ChessMove result = getCheckMove(b, side);
    if(result.first.second != -1){
        return result;
    }

    vector<PossibleMoves> lvl2MoveList = getLevel2MoveList(pm, b, side);
    //if we do have a list of moves that potentially leads to a capture
    //and no checks are avalible, we just capture a random piece.
    if(!lvl2MoveList.empty()){ result = randomMove(lvl2MoveList); }
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

void sortPosition(Board* b, vector<Position> arr){
    int i, j, n = arr.size();
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (b->getType(arr[j]).first > b->getType(arr[j+1]).first)
                swap(arr[j], arr[j + 1]);
}

void sortMoves(Board* b, vector<PossibleMoves> arr){
    int i, j, n = arr.size();
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (b->getType(arr[j].destination[0]).first > b->getType(arr[j+1].destination[0]).first)
                swap(arr[j], arr[j + 1]);
}

vector<PossibleMoves> getLevel4MoveList(vector<PossibleMoves> pm, Board* b, bool side){
    vector<PossibleMoves> lvl4MoveList = getLevel2MoveList(pm, b, side);
    for(auto lvl2move : lvl4MoveList){
        vector<Position> dest = lvl2move.destination;
        sortPosition(b, dest);
    }
    sortMoves(b, lvl4MoveList);
    return lvl4MoveList;
}
//level 4 is a bit more sophisticated than level 2 and 3
//as it applies the basic logic of 2 and 3
//while captures the most valuable piece if there is one
ChessMove getLevel4Move(vector<PossibleMoves> pm, Board* b, bool side){
    //first let's check if we do have a move that leads to a check
    ChessMove result = getCheckMove(b, side);
    if(result.first.second != -1){
        return result;
    }

    //sort the cpaturable move list by the value of the capturable piece
    vector<PossibleMoves> lvl3MoveList = getLevel3MoveList(pm, b, side);
    vector<PossibleMoves> lvl4MoveList = getLevel4MoveList(lvl3MoveList, b, side);

    //first lets check if there is a valuable piece we could both capture and avoid getting captured
    if(!lvl4MoveList.empty()){
        result.first = lvl4MoveList[lvl4MoveList.size()-1].start;
        vector<Position> dest = lvl4MoveList[lvl4MoveList.size()-1].destination;
        result.second = dest[dest.size()-1];
    }
    else {
        //if not we choose to capture the most valuable piece
        lvl4MoveList = getLevel4MoveList(pm, b, side);
        if(!lvl4MoveList.empty()){
            result.first = lvl4MoveList[lvl4MoveList.size()-1].start;
            vector<Position> dest = lvl4MoveList[lvl4MoveList.size()-1].destination;
            result.second = dest[dest.size()-1];
        }
        else{
            //if not even that we go with level 3's logic
            result = getLevel3Move(pm, b, side);
        }
    }
    return result;
}

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
            b->testMove(target, false);
            if(b->inCheck(side)){
                b->badMove(back, false);
                continue;
            }
            curMove.destination.emplace_back(d);
            b->badMove(back, false);
        }
        if(!curMove.destination.empty()){ pmList.emplace_back(curMove); }
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

    if(result.second.second == -2){
        ChessMove staleGame = make_pair(make_pair(A, -2), make_pair(A, -2));
        return staleGame;
    }

    //use our algorithm according to diff level to calculate the result and return
    b->nextMove(result, true);

    if(b->inCheck(!(this->side))){
        side ? cout<<"White is in check"<<endl : cout<<"Black is in check"<<endl;
    }
    //check if this move kills the opponent
    if(checkMate(b, side)){
        //check for stale games
        if(checkStale(b, side)){
            ChessMove staleGame = make_pair(make_pair(A, -2), make_pair(A, -2));
            return staleGame;
        }
        ChessMove endGame = make_pair(make_pair(A, -1), make_pair(A, -1));
        return endGame;
    }
    //check if a pawn can be promoted, and promote to queen
    if((result.second.second == 8 || result.second.second == 1)&& b->getType(result.second).first == PieceType::Pawn){
        b->promote(result.second, 'Q');
    }
    return result;
}
