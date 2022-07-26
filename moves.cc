#include "moves.h"
#include <iostream>

void Move::pop(){
    history.pop_back();
}

ChessMove Move::getLastMove(){
    if(history.size() > 0){
        ChessMove temp = history.back().first;
        pop();
        return temp;
        
    }
    return {{(locationx)1,0},{(locationx)1,0}};
}

ChessMove Move::readLastMove(){
    if(history.size() > 0){
        return history.back().first;
    }
    return {{(locationx)1,0},{(locationx)1,0}};
}

void Move::AddMove(ChessMove a, Piece b, Piece){
    history.push_back(MoveInfo{a,b});
}

