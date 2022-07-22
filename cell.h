#ifndef CELL_H_
#define CELL_H_
#include <vector>
#include "subject.h"

class ChessPiece;


class Cell : public Subject{
    ChessPiece* obj;
    std::vector<Observer*> ob;
  public:
    void notifyObserver();
    void getState();
    void setState(ChessPiece*);
    void getCoords();
    void getType();
};


#endif
