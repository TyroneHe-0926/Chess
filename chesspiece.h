#include <vector>
#include <string>
#include "board.h"
#include "types.h"

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

class ChessPiece{
public:
    virtual std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) = 0;
    virtual PieceType getType() = 0;
};

#endif
