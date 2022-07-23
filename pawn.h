#include "chesspiece.h"

#ifndef PAWN_H_
#define PAWN_H_
class Pawn : public ChessPiece{
    Piece piece;
public:
    Pawn(Piece);
    std::vector<chessmove> getAvalibleMoves(position, Board&) override;
    Piece getType() override;
};

#endif
