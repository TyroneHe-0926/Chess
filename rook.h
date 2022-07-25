#ifndef ROOK_H_
#define ROOK_H_
#include "chesspiece.h"


class Rook : public ChessPiece {
  public:
    Rook(bool);
    std::vector<Position> getAvalibleMoves(Position, Board*) override;
    Piece getType() override;
    ~Rook(){}
};

#endif
