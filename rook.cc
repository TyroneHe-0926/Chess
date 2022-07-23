#include "rook.h"

Rook::Rook(position p): ChessPiece(p) {
    piece.first = PieceType::Rook;
}

std::vector<chessmove> Rook::getAvalibleMoves(position, Board*) {
    return {};
}

Piece Rook::getType(){
    return piece;
}
