#ifndef CELL_H_
#define CELL_H_
#include <vector>
#include "subject.h"
#include "types.h"
#include "chesspiece.h"


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
