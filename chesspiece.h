#include <vector>
#include <string>
#include "board.h"
#include "types.h"

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

class ChessPiece{
public:
    virtual std::vector<chessmove> getAvalibleMoves(position, Board&) = 0;
    virtual Piece getType() = 0;
};

#endif
