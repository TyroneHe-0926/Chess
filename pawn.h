#include "chesspiece.h"

#ifndef PAWN_H_
#define PAWN_H_
class Pawn : public ChessPiece{
    std::string chessType;
public:
    std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) override;
    std::string getType() override;
};

#endif
