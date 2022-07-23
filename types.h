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

enum locationx{A,B,C,D,E,F,G,H};

typedef std::pair<PieceType, bool> Piece;
typedef std::pair<locationx, int> position;
typedef std::pair<position, position> move;
typedef std::pair<move, PieceType> moveinfo;

#endif
