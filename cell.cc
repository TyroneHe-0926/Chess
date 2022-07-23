#include "cell.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

position Cell::getCoords(){
    return Pos;
}

Piece Cell::getType(){
    if(!obj){
        return obj->getType();
    }
    return {PieceType::Empty, false};
}

Cell::Cell(position Pos): obj{nullptr}, Pos{Pos} {
    switch(Pos.second){
        case 2: 
        case 7:
            obj = new Pawn(Pos);
            break;
        case 1:
        case 8:
            switch(Pos.first){
                case A:
                case H:
                    obj = new Rook(Pos);
                    break;
                case B:
                case G:
                    obj = new Knight(Pos);
                    break;
                case C:
                case F:
                    obj = new Bishop(Pos);
                    break;
                case D:
                    obj = new Queen(Pos);
                    break;
                default:
                    obj = new King(Pos);
            }
            break;
    }
}

Cell::~Cell(){
    delete obj;
}