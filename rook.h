#ifndef ROOK_H_
#define ROOK_H_
#include "chesspiece.h"


class Rook : public ChessPiece {
  public:
    Rook(Piece);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
};

#endif
