#include "pawn.h"

Piece Pawn::getType(){
    return piece;
}

Pawn::Pawn(position p): ChessPiece(p) {
    piece.first = PieceType::Pawn;
}