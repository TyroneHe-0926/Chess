#include "chesspiece.h"

#ifndef QUEEN_H_
#define QUEEN_H_

class Queen : public ChessPiece{
    std::string chessType;
public:
    std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) override;
    std::string getType() override;
};

#endif
