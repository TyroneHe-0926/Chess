#include "king.h"
#include <utility>
#include "board.h"
using namespace std;

King::King(bool side): ChessPiece(side) {
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
            //right castling
            Position g = {(locationx)(x+2), y};
            Position h = {(locationx)(x+3), y};
            if(x == 5 && b->getType(retpos).first == PieceType::Empty && b->getType(g).first == PieceType::Empty
                    && moves == 0 && b->moved(h) == 0 && b->getType(h).first == PieceType::Rook){
                int num = 0;
                bool side = piece.second;
                num+=b->inCheck(side);
                b->testMove({pos, retpos}, false);
                num+=b->inCheck(side);
                b->badMove({retpos, pos}, false);
                b->testMove({pos, g}, false);
                num+=b->inCheck(side);
                b->badMove({g, pos}, false);
                if(num == 0){
                    result.emplace_back(g);
                }
            }
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
            Position a = {(locationx)(x-4), y};
            Position ba = {(locationx)(x-3), y};
            Position c = {(locationx)(x-2), y};
            if(x == 5 && b->getType(retpos).first == PieceType::Empty && b->getType(c).first == PieceType::Empty 
                && b->getType(ba).first == PieceType::Empty && moves == 0 && b->moved(a) == 0
                && b->getType(a).first == PieceType::Rook){
                int num = 0;
                bool side = piece.second;
                num+=b->inCheck(side);
                b->testMove({pos, retpos}, false);
                num+=b->inCheck(side);
                b->badMove({retpos, pos}, false);
                b->testMove({pos, ba}, false);
                num+=b->inCheck(side);
                b->badMove({ba, pos}, false);
                if(num == 0){
                    result.emplace_back(c);
                }
            }
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
