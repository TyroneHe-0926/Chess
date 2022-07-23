#include "knight.h"
#include <utility>

Knight::Knight(Position p): ChessPiece(p) {
    piece.first = PieceType::Knight;
}

std::vector<Position> Knight::getAvalibleMoves(Position pos, Board* board) {
    std::vector<Position> result;
    Position retpos;
    int x = (int) pos.first;
    int y = pos.second;

    if(y+2 <= 8 && x+1 <= 8){
        retpos.first = (locationx)(x+1);
        retpos.second = y+2;
        result.emplace_back(retpos); 
    }
    if(y+2 <= 8 && x-1 >= 0){ 
        retpos.first = (locationx)(x-1);
        retpos.second = y+2;
        result.emplace_back(retpos); 
    }
    if(y-2 >= 0 && x+1 <= 8){ 
        retpos.first = (locationx)(x+1);
        retpos.second = y-2;
        result.emplace_back(retpos); 
    }
    if(y-2 >= 0 && x-1 >= 0){ 
        retpos.first = (locationx)(x-1);
        retpos.second = y-2;
        result.emplace_back(retpos); 
    }
    if(y+1 <= 8 && x+2 <= 8){ 
        retpos.first = (locationx)(x+2);
        retpos.second = y+1;
        result.emplace_back(retpos); 
    }
    if(y+1 <= 8 && x-2 >= 0){ 
        retpos.first = (locationx)(x-2);
        retpos.second = y+1;
        result.emplace_back(retpos);
    }
    if(y-1 >= 0 && x+2 <= 8){
        retpos.first = (locationx)(x+2);
        retpos.second = y-1;
        result.emplace_back(retpos);
    }
    if(y-1 >= 0 && x-2 >= 0){ 
        retpos.first = (locationx)(x-2);
        retpos.second = y-1;
        result.emplace_back(retpos);
    }
    return result;
}

Piece Knight::getType(){
    return piece;
}
