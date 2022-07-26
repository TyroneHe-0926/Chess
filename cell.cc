#include "cell.h"
#include "observer.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <iostream>

Cell::Cell(Position Pos, std::shared_ptr<ChessPiece> a) : ob{}, obj{a}, 
                testobj{nullptr}, Pos{Pos} {}

void Cell::notifyObservers(){
    Cell temp{getCoords(), obj};
    ob[0]->notify(temp);
    ob[1]->notify(temp);
}

void Cell::attach(Observer* obs){
    ob.push_back(obs);
}

void Cell::setState(std::shared_ptr<ChessPiece>& next){
    if(obj){
        obj->moved();
    }
    obj.swap(next);
    notifyObservers();
}

std::vector<Position> Cell::getAvailableMoves(Board*b){
    return obj->getAvalibleMoves(this->getCoords(), b);
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

int Cell::moved(){
    if(obj){
        return obj->move();
    }
    return 0;
}

void Cell::test(){
    std::shared_ptr<ChessPiece> temp(nullptr);
    temp = obj;
    testobj = temp;

}

Cell::Cell(Position Pos, std::shared_ptr<ChessPiece> p, Observe a): ob{}, obj{p}, Pos{Pos} {
    attach(a.first);
    attach(a.second);
    notifyObservers();
}

Cell::~Cell(){}
