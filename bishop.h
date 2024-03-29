#ifndef BISHOP_H_
#define BISHOP_H_
#include "chesspiece.h"

class Bishop : public ChessPiece{
  public:
    Bishop(bool);
    std::vector<Position> getAvalibleMoves(Position, Board*) override;
    Piece getType() override;
    ~Bishop(){};
};

#endif
