#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
#include <iostream>
#include "cell.h"
#include "types.h"


class Board{
    std::vector<std::vector<Cell>> grid;
  public:
    void init();
    bool isWon();
    void undoMove();
    void nextMove(move);
    friend std::ostream& operator<<(std::ostream&, Board&);
};


#endif
