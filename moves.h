#ifndef MOVE_H_
#define MOVE_H_
#include <vector>
#include "types.h"

class Move{
    std::vector<MoveInfo> history;
    void pop();
  public:
    ChessMove getLastMove();
    ChessMove readLastMove();
    void AddMove(ChessMove, Piece, Piece);
    Move(){};
    ~Move(){};
};

#endif