#include "knight.h"
#include <utility>

Knight::Knight(Position p): ChessPiece(p) {
    piece.first = PieceType::Knight;
}

std::vector<Position> Knight::getAvalibleMoves(Position pos, Board* board) {
    std::vector<Position> result;
    int x = (int) pos.first, y = pos.second;
    if(y+2 <= 8 && x+1 <= 8){ result.emplace_back((locationx)x+1, y+2); }
    if(y+2 <= 8 && x-1 >= 0){ result.emplace_back((locationx)x-1, y+2); }
    if(y-2 >= 0 && x+1 <= 8){ result.emplace_back((locationx)x+1, y-2); }
    if(y-2 >= 0 && x-1 >= 0){ result.emplace_back((locationx)x-1, y-2); }
    if(y+1 <= 8 && x+2 <= 8){ result.emplace_back((locationx)x+2, y+1); }
    if(y+1 <= 8 && x-2 >= 0){ result.emplace_back((locationx)x-2, y+1); }
    if(y-1 >= 0 && x+2 <= 8){ result.emplace_back((locationx)x+2, y-1); }
    if(y-1 >= 0 && x-2 >= 0){ result.emplace_back((locationx)x-2, y-1); }
    return result;
}

Piece Knight::getType(){
    return piece;
}
