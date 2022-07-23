#ifndef KING_H_
#define KING_H_

#include "chesspiece.h"

class King : public ChessPiece {
    Piece piece;
public:
    King(Piece);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
};

#endif
