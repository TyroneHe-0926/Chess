#ifndef QUEEN_H_
#define QUEEN_H_
#include "chesspiece.h"

class Queen : public ChessPiece{
  public:
    Queen(position);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
    ~Queen(){}
};

#endif
