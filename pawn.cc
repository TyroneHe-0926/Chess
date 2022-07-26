#include "pawn.h"
#include <utility>
#include "board.h"
using namespace std;

Pawn::Pawn(bool side): ChessPiece(side) {
    piece.first = PieceType::Pawn;
}

std::vector<Position> Pawn::getAvalibleMoves(Position pos, Board* b) {
    std::vector<Position> result;
    Position retpos;
    int x = (int) pos.first;
    int y = pos.second;
    bool side = b->getType(pos).second;
    
    //for white player, pawn can only go up
    if(!side && y+1 <= 8){
        retpos.first = pos.first;
        retpos.second = y+1;
        //can only foward 1 cell if that cell is empty
        //also can only move forward by 2 cells if it hasn't moved yet
        if(b->getType(retpos).first == PieceType::Empty){
            result.emplace_back(retpos);
            retpos.second = y + 2;
            if(moves == 0 && b->getType(retpos).first == PieceType::Empty){
                result.emplace_back(retpos);
            }
        }
        //can only capture diagonally
        if(x+1 <= 8){
            retpos.first = (locationx)(x+1);
            retpos.second = y+1;
            if(b->getType(retpos).first != PieceType::Empty && 
            b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos);
            }
            retpos.second = 5;
            if(y == 5 && b->getType(retpos).first == PieceType::Pawn && b->moved(retpos) == 1){
                ChessMove lastmove = {{(locationx)x, 7}, {(locationx)x, 5}};
                if(lastmove == b->lastMove()){
                    retpos.second = 6;
                    result.emplace_back(retpos);
                }
            }
        }
        if(x-1 >= 1){
            retpos.first = (locationx)(x-1);
            retpos.second = y+1;
            if(b->getType(retpos).first != PieceType::Empty && 
            b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos);
            }
            retpos.second = 5;
            if(y == 5 && b->getType(retpos).first == PieceType::Pawn && b->moved(retpos) == 1){
                ChessMove lastmove = {{(locationx)x, 7}, {(locationx)x, 5}};
                if(lastmove == b->lastMove()){
                    retpos.second = 6;
                    result.emplace_back(retpos);
                }
            }
        }
    }

    //for black player, pawn can only go down
    if(side && y-1 >= 1){
        retpos.first = pos.first;
        retpos.second = y-1;
        //can only move foward 1 cell if that cell is empty
        if(b->getType(retpos).first == PieceType::Empty){
            result.emplace_back(retpos);
            retpos.second = y - 2;
            if(moves == 0 && b->getType(retpos).first == PieceType::Empty){
                result.emplace_back(retpos);
            }
        }
        //can only capture diagonally
        if(x+1 <= 8){
            retpos.first = (locationx)(x+1);
            retpos.second = y-1;
            if(b->getType(retpos).first != PieceType::Empty && 
            b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos);
            }
            retpos.second = 4;
            if(y == 4 && b->getType(retpos).first == PieceType::Pawn && b->moved(retpos) == 1){
                ChessMove lastmove = {{(locationx)x, 2}, {(locationx)x, 4}};
                if(lastmove == b->lastMove()){
                    retpos.second = 3;
                    result.emplace_back(retpos);
                }
            }
        }
        if(x-1 >= 1){
            retpos.first = (locationx)(x-1);
            retpos.second = y-1;
            if(b->getType(retpos).first != PieceType::Empty && 
            b->getType(retpos).second != b->getType(pos).second){
                result.emplace_back(retpos);
            }
            retpos.second = 4;
            if(y == 4 && b->getType(retpos).first == PieceType::Pawn && b->moved(retpos) == 1){
                ChessMove lastmove = {{(locationx)x, 2}, {(locationx)x, 4}};
                if(lastmove == b->lastMove()){
                    retpos.second = 3;
                    result.emplace_back(retpos);
                }
            }
        }
    }
    return result;
}

Piece Pawn::getType(){
    return piece;
}
