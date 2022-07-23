#ifndef KING_H_
#define KING_H_

#include "chesspiece.h"

class King : public ChessPiece {
  public:
    King(Position);
    std::vector<ChessMove> getAvalibleMoves(Position, Board*) override;
    Piece getType() override;
    ~King(){};
};

#endif
