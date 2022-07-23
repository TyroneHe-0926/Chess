#ifndef TYPE_H_
#define TYPE_H_
#include <utility>

enum PieceType{
    Pawn = 1,
    Bishop = 2,
    Rook = 3,
    Knight = 4,
    Queen = 5,
    King = 6,
    Empty = 0 // ChessPiece should not have this type. Cell.getType() should return this type though
};

enum locationx{A = 1,B = 2,C = 3,D = 4,E = 5,F = 6,G = 7,H = 8};

typedef std::pair<PieceType, bool> Piece;
typedef std::pair<locationx, int> position;
typedef std::pair<position, position> chessmove;
typedef std::pair<chessmove, PieceType> moveinfo;

#endif
