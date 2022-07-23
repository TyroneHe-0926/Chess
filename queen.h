#ifndef QUEEN_H_
#define QUEEN_H_
#include "chesspiece.h"

class Queen : public ChessPiece{
  public:
    Queen(Piece);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
};

#endif
