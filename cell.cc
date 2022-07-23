#include "cell.h"
#include "observer.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

Cell::Cell(Position Pos, std::shared_ptr<ChessPiece> a) : ob{}, obj{a}, Pos{Pos} {}

void Cell::notifyObservers(){
    Cell temp{getCoords(), obj};
    ob[0]->notify(temp);
    ob[0]->notify(temp);
}

void Cell::attach(Observer* obs){
    ob.push_back(obs);
}

void Cell::setState(std::shared_ptr<ChessPiece>* next){
    obj.swap(*next);
    notifyObservers();
}

Position Cell::getCoords(){
    return Pos;
}

Piece Cell::getType(){
    if(obj){
        return obj->getType();
    }
    return {PieceType::Empty, false};
}

Cell::Cell(Position Pos, Observe a): ob{}, obj{nullptr}, Pos{Pos} {
    attach(a.first);
    attach(a.second);
    switch(Pos.second){
        case 2: 
        case 7:
            obj = std::make_shared<Pawn>(Pawn(Pos));
            break;
        case 1:
        case 8:
            switch(Pos.first){
                case A:
                case H:
                    obj = std::make_shared<Rook>(Rook(Pos));
                    break;
                case B:
                case G:
                    obj = std::make_shared<Knight>(Knight(Pos));
                    break;
                case C:
                case F:
                    obj = std::make_shared<Bishop>(Bishop(Pos));
                    break;
                case D:
                    obj = std::make_shared<Queen>(Queen(Pos));
                    break;
                default:
                    obj = std::make_shared<King>(King(Pos));
            }
            break;
    }
    notifyObservers();
}

Cell::~Cell(){}
