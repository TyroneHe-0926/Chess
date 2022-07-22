#include <vector>
#include <string>
#include "board.h"

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

class ChessPiece{
public:
    virtual std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) = 0;
    virtual std::string getType() = 0;
};

#endif
