#ifndef BISHOP_H_
#define BISHOP_H_
#include "chesspiece.h"

class Bishop : public ChessPiece{
  public:
    Bishop(position);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
    ~Bishop(){};
};

#endif
