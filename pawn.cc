#include "pawn.h"

Pawn::Pawn(position p): ChessPiece(p) {
    piece.first = PieceType::Pawn;
}