#include "queen.h"

Queen::Queen(position p): ChessPiece(p) {
    piece.first = PieceType::Queen;
}

std::vector<chessmove> Queen::getAvalibleMoves(position, Board*) {
    return {};
}

Piece Queen::getType(){
    return piece;
}
