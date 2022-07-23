#include "cell.h"
#include "pawn.h"

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
            obj = new Pawn(Pos);
    }
}

Cell::~Cell(){
    delete obj;
}