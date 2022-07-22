#include "chesspiece.h"

#ifndef ROOK_H_
#define ROOK_H_

class Rook : public ChessPiece {
    std::string chessType;
public:
    std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) override;
    std::string getType() override;
};

#endif
