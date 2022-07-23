#include "chesspiece.h"

#ifndef BISHOP_H_
#define BISHOP_H_

class Bishop : public ChessPiece{
    PieceType chessType;
    int side;
public:
    Bishop(int, PieceType);
    std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) override;
    PieceType getType() override;
};

#endif
