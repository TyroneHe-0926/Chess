#include <utility>
#include "types.h"
#include "board.h"

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
public:
    virtual bool getSide() = 0;
    virtual ChessMove getNextMove(Board*) = 0;
    virtual ~Player() {};
    bool checkMate(Board* b, bool side);
};

#endif
