#include "chesspiece.h"

#ifndef KING_H_
#define KING_H_

class King : public ChessPiece {
    Piece piece;
public:
    King(Piece);
    std::vector<chessmove> getAvalibleMoves(position, Board&) override;
    Piece getType() override;
};

#endif
