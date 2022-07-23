#include "bishop.h"

std::vector<Position> Bishop::getAvalibleMoves(Position, Board*) {
    return {};
}

Bishop::Bishop(Position p): ChessPiece(p) {
    piece.first = PieceType::Bishop;
}

Piece Bishop::getType(){
    return piece;
}
