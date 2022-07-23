#ifndef QUEEN_H_
#define QUEEN_H_
#include "chesspiece.h"

class Queen : public ChessPiece{
  public:
    Queen(Position);
    std::vector<ChessMove> getAvalibleMoves(Position, Board*) override;
    Piece getType() override;
    ~Queen(){}
};

#endif
