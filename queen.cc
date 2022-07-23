#include "queen.h"

Queen::Queen(Position p): ChessPiece(p) {
    piece.first = PieceType::Queen;
}

std::vector<ChessMove> Queen::getAvalibleMoves(Position, Board*) {
    return {};
}

Piece Queen::getType(){
    return piece;
}
