#include "cell.h"

position Cell::getCoords(){
    return Pos;
}

Piece Cell::getType(){
    if(!obj){
        return obj->getType();
    }
    return {Empty, false};
}

Cell::Cell(position Pos): obj{nullptr}, Pos{Pos} {
    switch(Pos.second){
        case 2: obj
    }
}

Cell::~Cell(){
    delete obj;
}