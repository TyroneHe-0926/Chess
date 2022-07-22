#include "chesspiece.h"

#ifndef BISHOP_H_
#define BISHOP_H_

class Bishop : public ChessPiece{
    std::string chessType;
public:
    std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) override;
    std::string getType() override;
};

#endif
