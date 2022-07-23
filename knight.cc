#include "knight.h"

Knight::Knight(Position p): ChessPiece(p) {
    piece.first = PieceType::Knight;
}

std::vector<ChessMove> Knight::getAvalibleMoves(Position, Board*) {
    return {};
}

Piece Knight::getType(){
    return piece;
}
