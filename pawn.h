#ifndef PAWN_H_
#define PAWN_H_
#include "chesspiece.h"

class Pawn : public ChessPiece{
  public:
    Pawn(Position);
    std::vector<ChessMove> getAvalibleMoves(Position, Board*) override;
    Piece getType() override;
    ~Pawn(){};
};

#endif
