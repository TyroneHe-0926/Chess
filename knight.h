#include "chesspiece.h"

#ifndef KNIGHT_H_
#define KNIGHT_H_

class Knight : public ChessPiece {
    Piece piece;
public:
    Knight(Piece);
    std::vector<move> getAvalibleMoves(position, Board&) override;
    Piece getType() override;
};

#endif
