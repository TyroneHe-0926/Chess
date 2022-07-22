#include <utility>

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
public:
    virtual int getSide() = 0;
    virtual std::pair<std::pair<char, int>, std::pair<char, int>> getNextMove() = 0;
};

#endif
