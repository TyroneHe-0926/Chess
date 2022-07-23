#ifndef KNIGHT_H_
#define KNIGHT_H_
#include "chesspiece.h"

class Knight : public ChessPiece {
  public:
    Knight(position);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
    ~Knight(){};
};

#endif
