#include "pawn.h"

Pawn::Pawn(Position p): ChessPiece(p) {
    piece.first = PieceType::Pawn;
}

std::vector<ChessMove> Pawn::getAvalibleMoves(Position, Board*) {
    return {};
}

Piece Pawn::getType(){
    return piece;
}
