#include "chesspiece.h"

#ifndef ROOK_H_
#define ROOK_H_

class Rook : public ChessPiece {
    Piece piece;
public:
    Rook(Piece);
    std::vector<move> getAvalibleMoves(position, Board&) override;
    Piece getType() override;
};

#endif
