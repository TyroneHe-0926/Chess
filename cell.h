#ifndef CELL_H_
#define CELL_H_
#include <vector>
#include <memory>
#include "types.h"

class Observer;
class ChessPiece;
class Board;

class Cell{
    std::vector<Observer*> ob;                    //Pair of observers to notify
    std::shared_ptr<ChessPiece> obj;              //Pointer to a chess piece if it exists
    std::shared_ptr<ChessPiece> testobj;          //Pointer to a chess piece if it exists
    Position Pos;                                 //The Position of the cell in the grid
    void notifyObservers();
    void attach(Observer*);                       //Observers should only be attached at initialization
    Cell(Position Pos, std::shared_ptr<ChessPiece> a);
  public:
    void setState(std::shared_ptr<ChessPiece>&);  //Insert the new piece and return the old one
    std::vector<Position> getAvailableMoves(Board*);
    Position getCoords();                         //Return the Coordinates of the cell
    Piece getType();                              //Return the piece information
    int moved();                                  //Returns the number of moves made
    void test();
    Cell(Position Pos, std::shared_ptr<ChessPiece> ,Observe a);                //ctor
    ~Cell();                                      //dtor
};

#endif
