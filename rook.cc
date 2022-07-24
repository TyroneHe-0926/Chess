#include "rook.h"
#include <utility>
#include "board.h"
using namespace std;

Rook::Rook(Position p): ChessPiece(p) {
    piece.first = PieceType::Rook;
}

std::vector<Position> Rook::getAvalibleMoves(Position pos, Board* b) {
    vector<Position> result;
    //Rook right now just checks col and row for basic movements
    ChessPiece::checkRowCol(b, result, pos);
    return result;
}

Piece Rook::getType(){
    return piece;
}
