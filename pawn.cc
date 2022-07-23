#include "pawn.h"

Pawn::Pawn(position p): piece{PieceType::Pawn,false} {
    if(p.second == 2){
        piece.second = true;
    }
}