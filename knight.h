#include "chesspiece.h"

#ifndef KNIGHT_H_
#define KNIGHT_H_

class Knight : public ChessPiece {
    std::string chessType;
public:
    std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) override;
    std::string getType() override;
};

#endif
