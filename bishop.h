#include "chesspiece.h"

#ifndef BISHOP_H_
#define BISHOP_H_

class Bishop : public ChessPiece{
    Piece piece;
public:
    Bishop(Piece);
    std::vector<move> getAvalibleMoves(position, Board&) override;
    Piece getType() override;
};

#endif
