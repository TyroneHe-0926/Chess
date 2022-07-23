#include "queen.h"

Queen::Queen(position p): ChessPiece(p) {
    piece.first = PieceType::Queen;
}