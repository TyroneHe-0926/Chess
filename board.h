#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
#include <iostream>
#include "cell.h"
#include "textdisplay.h"
#include "gui.h"
#include "moves.h"
#include "types.h"

class Board{
    std::vector<std::vector<Cell>> grid;
    TextDisplay* td;
    GUI* gui;
    Move list;
    void enPassant(ChessMove);
    void castling(ChessMove);
  public:
    bool init(std::istream& in, bool);               //handles setup command
    bool inCheck(bool side);
    void undoMove();
    void nextMove(ChessMove, bool);
    void testMove(ChessMove, bool);
    void badMove(ChessMove, bool);
    ChessMove lastMove();
    Piece getType(Position);
    int moved(Position);
    std::vector<PossibleMoves> getAllAvailableMoves(bool);
    void promote(Position, char);
    Board();
    ~Board();
    friend std::ostream& operator<<(std::ostream&, Board&);
};


#endif
