#ifndef TYPE_H_
#define TYPE_H_
#include <utility>

enum PieceType{
    Pawn,
    Bishop,
    Rook,
    Knight,
    Queen,
    King
};

enum locationx{A,B,C,D,E,F,G,H};


typedef std::pair<locationx, int> position;
typedef std::pair<position, position> move;
typedef std::pair<move, PieceType> moveinfo;

#endif
