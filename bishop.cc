#include "bishop.h"

Bishop::Bishop(position p): ChessPiece(p) {
    piece.first = PieceType::Bishop;
}
