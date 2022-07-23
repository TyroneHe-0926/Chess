#include "knight.h"
#include <utility>
#include "board.h"

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
        if(board->getType(retpos).second != board->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }
    if(y+2 <= 8 && x-1 >= 1){ 
        retpos.first = (locationx)(x-1);
        retpos.second = y+2;
        if(board->getType(retpos).second != board->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }
    if(y-2 >= 1 && x+1 <= 8){ 
        retpos.first = (locationx)(x+1);
        retpos.second = y-2;
        if(board->getType(retpos).second != board->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }
    if(y-2 >= 1 && x-1 >= 1){ 
        retpos.first = (locationx)(x-1);
        retpos.second = y-2;
        if(board->getType(retpos).second != board->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }
    if(y+1 <= 8 && x+2 <= 8){ 
        retpos.first = (locationx)(x+2);
        retpos.second = y+1;
        if(board->getType(retpos).second != board->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }
    if(y+1 <= 8 && x-2 >= 1){ 
        retpos.first = (locationx)(x-2);
        retpos.second = y+1;
        if(board->getType(retpos).second != board->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }
    if(y-1 >= 1 && x+2 <= 8){
        retpos.first = (locationx)(x+2);
        retpos.second = y-1;
        if(board->getType(retpos).second != board->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }
    if(y-1 >= 1 && x-2 >= 0){ 
        retpos.first = (locationx)(x-2);
        retpos.second = y-1;
        if(board->getType(retpos).second != board->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }
    return result;
}

Piece Knight::getType(){
    return piece;
}
