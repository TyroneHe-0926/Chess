#ifndef CELL_H_
#define CELL_H_
#include <vector>
#include <memory>
#include "types.h"

class Observer;
class ChessPiece;

class Cell{
    std::vector<Observer*> ob;                    //Pair of observers to notify
    std::shared_ptr<ChessPiece> obj;              //Pointer to a chess piece if it exists
    position Pos;                                 //The position of the cell in the grid
    void notifyObservers();
    void attach(Observer*);                       //Observers should only be attached at initialization
    Cell(position Pos, std::shared_ptr<ChessPiece> a);
  public:
    void setState(std::shared_ptr<ChessPiece>*);  //Insert the new piece and return the old one
    position getCoords();                         //Return the Coordinates of the cell
    Piece getType();                              //Return the piece information
    Cell(position Pos, Observe a);                //ctor
    ~Cell();                                      //dtor
};

#endif
