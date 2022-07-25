#include "bishop.h"
#include <utility>
#include "board.h"
using namespace std;

std::vector<Position> Bishop::getAvalibleMoves(Position pos, Board* b) {
    vector<Position> result;
    //Bishops just need to check the diagnols
    ChessPiece::checkDiag(b, result, pos);
    return result;
}

Bishop::Bishop(bool side): ChessPiece(side) {
    piece.first = PieceType::Bishop;
}

Piece Bishop::getType(){
    return piece;
}
