#ifndef CELL_H_
#define CELL_H_
#include <vector>
#include <memory>
#include "subject.h"
#include "types.h"

class ChessPiece;

class Cell : public Subject{
    ChessPiece* obj;
    position Pos;
  public:
    void notifyObserver();
    void getState();
    void setState(ChessPiece*);
    position getCoords();
    Piece getType();
    Cell(position Pos);
    ~Cell();
};


#endif
