#include "king.h"

King::King(Position p): ChessPiece(p) {
    piece.first = PieceType::King;
}

std::vector<ChessMove> King::getAvalibleMoves(Position, Board*) {
    return {};
}

Piece King::getType(){
    return piece;
}
