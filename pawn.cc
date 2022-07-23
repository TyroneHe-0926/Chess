#include "pawn.h"

Pawn::Pawn(position p): ChessPiece(p) {
    piece.first = PieceType::Pawn;
}

std::vector<chessmove> Pawn::getAvalibleMoves(position, Board*) {
    return {};
}

Piece Pawn::getType(){
    return piece;
}
