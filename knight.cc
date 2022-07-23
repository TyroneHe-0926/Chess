#include "knight.h"

Knight::Knight(position p): ChessPiece(p) {
    piece.first = PieceType::Knight;
}

std::vector<chessmove> Knight::getAvalibleMoves(position, Board*) {
    return {};
}

Piece Knight::getType(){
    return piece;
}
