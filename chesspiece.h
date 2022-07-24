#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <vector>
#include "types.h"

class Board;

class ChessPiece{
  protected:
    Piece piece;
  public:
    virtual std::vector<Position> getAvalibleMoves(Position, Board*) = 0;
    virtual Piece getType() = 0;
    ChessPiece(Position p);
    virtual ~ChessPiece(){};
    static void checkDiag(Board*, std::vector<Position>&, Position);
    static void checkRowCol(Board*, std::vector<Position>&, Position);
};

#endif
