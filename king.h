#include "chesspiece.h"

#ifndef KING_H_
#define KING_H_

class King : public ChessPiece {
    std::string chessType;
public:
    std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) override;
    std::string getType() override;
};

#endif
