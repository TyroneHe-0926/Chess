#include <utility>
#include "types.h"

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
public:
    virtual bool getSide() = 0;
    virtual move getNextMove() = 0;
};

#endif
