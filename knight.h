#ifndef KNIGHT_H_
#define KNIGHT_H_
#include "chesspiece.h"

class Knight : public ChessPiece {
    Piece piece;
public:
    Knight(Piece);
    std::vector<chessmove> getAvalibleMoves(position, Board*) override;
    Piece getType() override;
};

#endif
