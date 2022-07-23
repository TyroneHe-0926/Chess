#include "queen.h"

Queen::Queen(Position p): ChessPiece(p) {
    piece.first = PieceType::Queen;
}

std::vector<Position> Queen::getAvalibleMoves(Position, Board*) {
    return {};
}

Piece Queen::getType(){
    return piece;
}
