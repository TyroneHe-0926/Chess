#include "queen.h"
#include <utility>
#include "board.h"
using namespace std;

Queen::Queen(Position p): ChessPiece(p) {
    piece.first = PieceType::Queen;
}

std::vector<Position> Queen::getAvalibleMoves(Position pos, Board* b) {
    vector<Position> result;
    //Queen needs to check both diagnols and rows and columns
    ChessPiece::checkDiag(b, result, pos);
    ChessPiece::checkRowCol(b, result, pos);
    return result;
}

Piece Queen::getType(){
    return piece;
}
