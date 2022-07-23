#ifndef BISHOP_H_
#define BISHOP_H_
#include "chesspiece.h"

class Bishop : public ChessPiece{
    Piece piece;
public:
    Bishop(Piece);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
};

#endif
