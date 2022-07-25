#ifndef KING_H_
#define KING_H_
#include <utility>
#include "chesspiece.h"

class King : public ChessPiece {
  public:
    King(bool);
    std::vector<Position> getAvalibleMoves(Position, Board*) override;
    Piece getType() override;
    ~King(){};
};

#endif
