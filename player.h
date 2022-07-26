#include <utility>
#include "types.h"
#include "board.h"

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
public:
    virtual ChessMove getNextMove(Board*) = 0;
    virtual ~Player() {};
    bool checkMate(Board* b, bool side);
    bool checkStale(Board* b, bool side);
    virtual PlayerType getPlayerType() = 0;
};

#endif
