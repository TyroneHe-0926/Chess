#ifndef KING_H_
#define KING_H_

#include "chesspiece.h"

class King : private ChessPiece {
  public:
    King(position);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
    ~King(){};
};

#endif
