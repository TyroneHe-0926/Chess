#ifndef KNIGHT_H_
#define KNIGHT_H_
#include "chesspiece.h"

class Knight : public ChessPiece {
  public:
    Knight(Position);
    std::vector<Position> getAvalibleMoves(Position, Board*) override;
    Piece getType() override;
    ~Knight(){};
};

#endif
