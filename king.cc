#include "king.h"

King::King(position p): ChessPiece(p) {
    piece.first = PieceType::King;
}

Piece King::getType(){
    return piece;
}
