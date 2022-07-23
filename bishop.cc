#include "bishop.h"

std::vector<chessmove> Bishop::getAvalibleMoves(position, Board*) {
    return {};
}

Bishop::Bishop(position p): ChessPiece(p) {
    piece.first = PieceType::Bishop;
}

Piece Bishop::getType(){
    return piece;
}
