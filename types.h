#ifndef TYPE_H_
#define TYPE_H_
#include <utility>

class Observer;

enum class PieceType{
    Pawn = 1,
    Rook = 2,
    Knight = 3,
    Bishop = 4,
    Queen = 5,
    King = 6,
    Empty = 0 // ChessPiece should not have this type. Cell.getType() should return this type though
};

enum locationx{A = 1,B = 2,C = 3,D = 4,E = 5,F = 6,G = 7,H = 8};

typedef std::pair<PieceType, bool> Piece;
typedef std::pair<locationx, int> position;
typedef std::pair<position, position> chessmove;
typedef std::pair<chessmove, PieceType> moveinfo;
typedef std::pair<Observer*, Observer*> Observe;

#endif
