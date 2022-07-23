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
    bool checkmate;
  public:
    void init();
    bool isWon();
    void undoMove();
    void nextMove(ChessMove);
    Piece getType(Position);
    std::vector<ChessMove> getMoveList(bool side);
    Board();
    ~Board();
    friend std::ostream& operator<<(std::ostream&, Board&);
};


#endif
