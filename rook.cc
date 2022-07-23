#include "rook.h"

Rook::Rook(Position p): ChessPiece(p) {
    piece.first = PieceType::Rook;
}

std::vector<ChessMove> Rook::getAvalibleMoves(Position, Board*) {
    return {};
}

Piece Rook::getType(){
    return piece;
}
