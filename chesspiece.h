#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <vector>
#include "types.h"

class Board;

class ChessPiece{
  protected:
    Piece piece;
  public:
    virtual std::vector<chessmove> getAvalibleMoves(position, Board*) = 0;
    virtual Piece getType() = 0;
    ChessPiece(position p);
    virtual ~ChessPiece(){};
};

#endif
