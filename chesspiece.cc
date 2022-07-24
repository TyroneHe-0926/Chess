#include "chesspiece.h"
#include "board.h"

ChessPiece::ChessPiece(Position p) {
    if(p.second == 1 || p.second == 2){
        piece.second = false;
    }
    else{
        piece.second = true;
    }
};

void ChessPiece::checkDiag(Board* b, std::vector<Position>& result, Position pos){
    int x = (int) pos.first;
    int y = pos.second;
    Position retpos;
    //diag check top right
    for(int row = y+1, col = x+1; row <= 8 && col <= 8; ++row, ++col){
        retpos.first = (locationx)(col);
        retpos.second = row;
        if(b->getType(retpos).first == PieceType::Empty){
            //if that cell is empty, we know that is valid
            result.emplace_back(retpos);
        }else if(b->getType(retpos).second != b->getType(pos).second){
            //if that cell is occupied by the enemy, we know its valid
            //but this is the end for that diagnol line
            result.emplace_back(retpos);
            break;
        }
        else {break; } //else its just not a valid cell
    }

    //diag check top left
    for(int row = y+1, col = x-1; row <= 8 && col >= 1; ++row, --col){
        retpos.first = (locationx)(col);
        retpos.second = row;
        if(b->getType(retpos).first == PieceType::Empty){
            result.emplace_back(retpos);
        }else if(b->getType(retpos).second != b->getType(pos).second){
            result.emplace_back(retpos);
            break;
        }
        else {break;}
    }

    //diag check bottom right
    for(int row = y-1, col = x+1; row >= 1 && col <= 8; --row, ++col){
        retpos.first = (locationx)(col);
        retpos.second = row;
        if(b->getType(retpos).first == PieceType::Empty){
            result.emplace_back(retpos);
        }else if(b->getType(retpos).second != b->getType(pos).second){
            result.emplace_back(retpos);
            break;
        }
        else {break;}
    }

    //diag check bottom left
    for(int row = y-1, col = x-1; row >= 1 && col >= 1; --row, --col){
        retpos.first = (locationx)(col);
        retpos.second = row;
        if(b->getType(retpos).first == PieceType::Empty){
            result.emplace_back(retpos);
        }else if(b->getType(retpos).second != b->getType(pos).second){
            result.emplace_back(retpos);
            break;
        }
        else {break;}
    }
}

void ChessPiece::checkRowCol(Board* b, std::vector<Position>& result, Position pos){
    int x = (int) pos.first;
    int y = pos.second;
    Position retpos;
    //col check to the right
    for(int col = x+1; col <= 8; ++col){
        retpos.first = (locationx) col;
        retpos.second = y;
        if(b->getType(retpos).first == PieceType::Empty){
            //if that cell is empty, we know that is valid
            result.emplace_back(retpos);
        }else if(b->getType(retpos).second != b->getType(pos).second){
            //if that cell is occupied by the enemy, we know its valid
            //but this is the end for this col
            result.emplace_back(retpos);
            break;
        }
        else {break;} //else its just not a valid cell
    }

    // //col check to the left
    for(int col = x-1; col >= 1; --col){
        retpos.first = (locationx)(col);
        retpos.second = y;
        if(b->getType(retpos).first == PieceType::Empty){
            result.emplace_back(retpos);
        }else if(b->getType(retpos).second != b->getType(pos).second){
            result.emplace_back(retpos);
            break;
        }
        else {break;}
    }

    // //row check to the top
    for(int row = y+1; row <= 8; ++row){
        retpos.first = pos.first;
        retpos.second = row;
        if(b->getType(retpos).first == PieceType::Empty){
            result.emplace_back(retpos);
        }else if(b->getType(retpos).second != b->getType(pos).second){
            result.emplace_back(retpos);
            break;
        }
        else {break;}
    }

    // //row check to the bottom
    for(int row = y-1; row >= 1; --row){
        retpos.first = pos.first;
        retpos.second = row;
        if(b->getType(retpos).first == PieceType::Empty){
            result.emplace_back(retpos);
        }else if(b->getType(retpos).second != b->getType(pos).second){
            result.emplace_back(retpos);
            break;
        }
        else {break;}
    }
}
