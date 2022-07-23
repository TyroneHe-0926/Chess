#include "chesspiece.h"

#ifndef QUEEN_H_
#define QUEEN_H_

class Queen : public ChessPiece{
    Piece piece;
public:
    Queen(Piece);
    std::vector<move> getAvalibleMoves(position, Board&) override;
    Piece getType() override;
};

#endif
