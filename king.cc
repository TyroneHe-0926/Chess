#include "king.h"
#include <utility>
#include "board.h"
using namespace std;

King::King(Position p): ChessPiece(p) {
    piece.first = PieceType::King;
}

std::vector<Position> King::getAvalibleMoves(Position pos, Board* b) {
    std::vector<Position> result;
    Position retpos;
    int x = (int) pos.first;
    int y = pos.second;

    //right half
    if(x+1 <= 8){
        //check top right
        if(y+1 <= 8){
            retpos.first = (locationx)(x+1);
            retpos.second = y+1;
            if(b->getType(retpos).first == PieceType::Empty || b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos); 
            }
        }
        //check middle right
        retpos.first = (locationx)(x+1);
        retpos.second = y;
        if(b->getType(retpos).first == PieceType::Empty || b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos); 
        }
        //check bottom right
        if(y-1 >= 1){
            retpos.first = (locationx)(x+1);
            retpos.second = y-1;
            if(b->getType(retpos).first == PieceType::Empty || b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos); 
            }
        }
    }

    //left half
    if(x-1 >= 1){
       //check top left
        if(y+1 <= 8){
            retpos.first = (locationx)(x-1);
            retpos.second = y+1;
            if(b->getType(retpos).first == PieceType::Empty || b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos); 
            }
        }
        //check middle left
        retpos.first = (locationx)(x-1);
        retpos.second = y;
        if(b->getType(retpos).first == PieceType::Empty || b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos); 
        }
        //check bottom left
        if(y-1 >= 1){
            retpos.first = (locationx)(x-1);
            retpos.second = y-1;
            if(b->getType(retpos).first == PieceType::Empty || b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos); 
            }
        }
    }

    //check top mid
    if(y+1 <= 8){
        retpos.first = pos.first;
        retpos.second = y+1;
        if(b->getType(retpos).first == PieceType::Empty || b->getType(retpos).second != b->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }

    //check bottom mid
    if(y-1 >= 1){
        retpos.first = pos.first;
        retpos.second = y-1;
        if(b->getType(retpos).first == PieceType::Empty || b->getType(retpos).second != b->getType(pos).second){
            result.emplace_back(retpos); 
        }
    }

    return result;
}

Piece King::getType(){
    return piece;
}
