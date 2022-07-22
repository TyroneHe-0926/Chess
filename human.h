#include "player.h"

#ifndef HUMAN_H_
#define HUMAN_H_

class Human : public Player{
    int side;
public:
    Human(int);
    int getSide() override;
    std::pair<std::pair<char, int>, std::pair<char, int>> getNextMove() override;
};

#endif
