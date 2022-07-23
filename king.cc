#include "king.h"

King::King(position p): ChessPiece(p) {
    piece.first = PieceType::King;
}

std::vector<chessmove> King::getAvalibleMoves(position, Board*) {
    return {};
}

Piece King::getType(){
    return piece;
}
