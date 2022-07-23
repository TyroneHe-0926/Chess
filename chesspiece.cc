#include "chesspiece.h"

ChessPiece::ChessPiece(Position p) {
    if(p.second == 1 || p.second == 2){
        piece.second = false;
    }
    else{
        piece.second = true;
    }
};