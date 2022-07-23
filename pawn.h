#ifndef PAWN_H_
#define PAWN_H_
#include "chesspiece.h"

class Pawn : public ChessPiece{
  public:
    Pawn(position);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
    ~Pawn(){};
};

#endif
